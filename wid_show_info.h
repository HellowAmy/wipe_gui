#ifndef WID_SHOW_INFO_H
#define WID_SHOW_INFO_H

#include <QWidget>
#include <QLabel>
#include <QDragEnterEvent>
#include <QDropEvent>
#include <QMimeData>

class wid_show_info : public QWidget
{
    Q_OBJECT
public:
    explicit wid_show_info(QWidget *parent = nullptr);
    void set_size(QSize size);
    QStringList get_files();
    
signals:
    emit void fa_drop_files();
    
protected:
    QLabel *lab_info;
    QStringList list_drop;//拖动文件列表

    //开启允许拖动权限
    void dragEnterEvent(QDragEnterEvent*event) override;
    void dropEvent(QDropEvent*event) override;//拖动进入事件
};

#endif // WID_SHOW_INFO_H
