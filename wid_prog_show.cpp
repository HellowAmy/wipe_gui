#include "wid_prog_show.h"

#include <QDebug>
#define out qDebug()

wid_prog_show::wid_prog_show(QWidget *parent) : QWidget(parent)
{
    int wide = 350;
    int high = 30;
    this->resize(wide,high*3);

    lab_path = new QLabel(this);
    lab_path->setFrameShape(QFrame::Box);
    lab_path->setAlignment(Qt::AlignCenter);
    lab_path->resize(wide,high);

    prog_fils = new QProgressBar(this);
    prog_fils->setValue(50);
    prog_fils->resize(wide,high);

    prog_all = new QProgressBar(this);
    prog_all->setValue(50);
    prog_all->resize(wide,high);

    move.add_wid(lab_path);
    move.add_wid(prog_fils);
    move.add_wid(prog_all);
    move.set_vert(QPoint(0,0));

    timer = new QTimer(this);

    connect(timer,&QTimer::timeout,this,[=](){
        //files为累计粉碎的文件数，总数自己求，now为第几遍，end为粉碎次数
        work.show_progress(files,now,end);

        prog_fils->setValue(((now+1)*100)/end);
        prog_all->setValue((files*100)/all);

        out<<files<<"|"<<now<<"|"<<end<<"|"<<all;
        out<<"timeout update progress";
    });

    connect(this,&wid_prog_show::fa_finish,this,[=](){
        timer->stop();
    });

    work.func_finish = [=](int ret){
        if(ret == 0) lab_path->setText("粉碎完成");
        else lab_path->setText("粉碎失败");
        emit fa_finish((ret>0 ? true:false));
    };

}

void wid_prog_show::open_work(vector<string> vec)
{
    //获取信息
    if(vec.size() > 2)
    {
        QFileInfo info(QString::fromStdString(vec[2]));
        if(info.isDir())
        {
            QStringList list = get_files_name(QString::fromStdString(vec[2]));
            all = list.size();
        }
    }
    lab_path->setText(QString::fromStdString(vec[2]));

    //开启任务线程
    std::thread th_temp(&inter_wipe::open_work,work,vec);
    th_temp.detach();

    //启动进度定时器
    timer->start(500);
}


//获取文件名
QStringList wid_prog_show::get_files_name(QString path)
{
    QStringList list;

    QFileInfoList list_info = get_files_info(path);
    for(int i=0;i<list_info.size();i++)
    {
        QFileInfo info(list_info[i]);
        list<<info.absoluteFilePath();
    }

    return list;
}

//获取文件全部信息
QFileInfoList wid_prog_show::get_files_info(QString path)
{
    QDir dir(path);
    QFileInfoList list_file = dir.entryInfoList
            (QDir::Files | QDir::Hidden | QDir::NoSymLinks);
    QFileInfoList list_dir = dir.entryInfoList
            (QDir::Dirs | QDir::NoDotAndDotDot);

    for(int i=0;i<list_dir.size();i++)
    {
         QString name = list_dir.at(i).absoluteFilePath();
         QFileInfoList child_file_list = get_files_info(name);
         list_file.append(child_file_list);
    }

    return list_file;
}
