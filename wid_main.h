#ifndef WID_MAIN_H
#define WID_MAIN_H

#include <QWidget>
#include <QPushButton>
#include <QLineEdit>
#include <QDialog>

#include <vector>
using std::vector;

#include "wid_prog_show.h"
#include "wid_show_info.h"
#include "qt_move_it.h"

class wid_main : public QWidget
{
    Q_OBJECT
public:
    explicit wid_main(QWidget *parent = nullptr);
    ~wid_main();

signals:

protected:
    QWidget *wid_prog;
    QLineEdit *edit_cmd;
    QLineEdit *edit_op;
    QLineEdit *edit_path;
    QPushButton *butt_cmd;
    wid_show_info *wid_show;

    qt_move_it move_prog;
    vector<wid_prog_show*> vec_prog;
};

#endif // WID_MAIN_H
