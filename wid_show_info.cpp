#include "wid_show_info.h"

wid_show_info::wid_show_info(QWidget *parent) : QWidget(parent)
{
    this->setAcceptDrops(true);

    lab_info = new QLabel(this);
    lab_info->setAttribute(Qt::WA_TransparentForMouseEvents);
    lab_info->setFrameShape(QFrame::Panel);
    lab_info->setAlignment(Qt::AlignCenter);
    lab_info->setText("<< 将粉碎文件拖入这里 >>");
    lab_info->show();
}

void wid_show_info::set_size(QSize size)
{
    this->resize(size);
    lab_info->resize(size - QSize(10,10));
}

QStringList wid_show_info::get_files()
{
    return list_drop;
}

void wid_show_info::dragEnterEvent(QDragEnterEvent *event)
{
    //放行，否则不会执行dropEvent()函数
    event->acceptProposedAction();
}

void wid_show_info::dropEvent(QDropEvent *event)
{
    //
    QList<QUrl> list_files = event->mimeData()->urls();
    if(list_files.isEmpty() == false)
    {
        list_drop.clear();
        for(int i=0;i<list_files.size();i++)
        {
            QString path = list_files[i].toString();
            list_drop += path;
        }

        emit fa_drop_files();
    }
}
