#ifndef WID_PROG_SHOW_H
#define WID_PROG_SHOW_H

#include <QWidget>
#include <QProgressBar>
#include <QLabel>
#include <QPushButton>
#include <QFileInfoList>
#include <QFileInfo>
#include <QDir>

#include <vector>
#include <thread>
#include <QTimer>

#include "lib/inter_wipe.h"
#include "qt_move_it.h"

using namespace std;

class wid_prog_show : public QWidget
{
    Q_OBJECT
public:
    explicit wid_prog_show(QWidget *parent = nullptr);
    void open_work(vector<string> vec);

signals:
    emit void fa_finish(bool ok);

protected:
    inter_wipe work;
    qt_move_it move;

    QLabel *lab_path;
    QProgressBar *prog_all;
    QProgressBar *prog_fils;
    QTimer *timer;

    int files;
    int now;
    int end;
    int all;

    QStringList get_files_name(QString path);
    QFileInfoList get_files_info(QString path);
};

#endif // WID_PROG_SHOW_H
