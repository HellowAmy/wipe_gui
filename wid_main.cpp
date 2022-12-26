#include "wid_main.h"

#include <QDebug>
#define out qDebug()

wid_main::wid_main(QWidget *parent) : QWidget(parent)
{
    this->setWindowTitle("");
    this->setFixedSize(400 + 5*5,135);

    QWidget *wid_prog = new QWidget;
    wid_prog->resize(350,90);

    edit_cmd = new QLineEdit(this);
    edit_cmd->setText("wipe");
    edit_cmd->setAlignment(Qt::AlignCenter);
    edit_cmd->resize(50,30);

    edit_op = new QLineEdit(this);
    edit_op->setText("-rsfc");
    edit_op->setAlignment(Qt::AlignCenter);
    edit_op->resize(100,30);

    edit_path = new QLineEdit(this);
    edit_path->setText("");
    edit_path->resize(200,30);

    butt_cmd = new QPushButton(this);
    butt_cmd->resize(50,30);
    butt_cmd->setText("执行");

    {
        qt_move_it move;
        move.add_wid(edit_cmd);
        move.add_wid(edit_op);
        move.add_wid(edit_path);
        move.add_wid(butt_cmd);
        move.set_space(5);
        move.set_hori(QPoint(5,5));
    }

    wid_show = new wid_show_info(this);
    wid_show->move(5,40);
    wid_show->set_size(QSize(400 + 5*5,100));
    


    connect(wid_show,&wid_show_info::fa_drop_files,this,[=](){

        QStringList list = wid_show->get_files();
        for(int i=0;i<list.size();i++)
        {
            QString path = list[i].section("file://",1,1);
            vector<string> vec;
            vec.push_back("./wipe");
            vec.push_back("-rsfc");
            vec.push_back(path.toStdString());

            wid_prog_show *temp = new wid_prog_show(wid_prog);
            temp->open_work(vec);
            temp->show();

            vec_prog.push_back(temp);
            move_prog.add_wid(temp);
            move_prog.set_vert(QPoint(0,0));


//            //释放内存
//            connect(temp,&wid_prog_show::fa_finish,[=](bool){
//                for(auto it = vec_prog.begin();it != vec_prog.end();it++)
//                {
//                    if(*it == temp)
//                    {
////                        delete *it;
////                        vec_prog.erase(it);
////                        break;
//                    }
//                }
//            });
        }

        wid_prog->resize(350,vec_prog.size()*90);
        wid_prog->show();

        out<<list;
    });




}

wid_main::~wid_main()
{
    delete wid_prog;

    for(auto &a:vec_prog) { delete a; }
}
