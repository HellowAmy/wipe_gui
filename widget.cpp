#include "widget.h"
#include "ui_widget.h"

#include "lib/inter_wipe.h"
#include "wid_prog_show.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    //blkid -o list |grep /dev/ |grep -v '/dev/sda'

    this->show();

    wid_prog_show *hu = new wid_prog_show(this);
    vector<string> vec;
    vec.push_back("./wipe");
    vec.push_back("-rsfc");
    vec.push_back("/home/red/test/gz/vs_jctools");
    hu->open_work(vec);
    hu->show();

//    cout<<"asdhasdj11"<<endl;
//    inter_wipe ji;


//    vector<string> vec;
//    vec.push_back("./wipe");
//    vec.push_back("-rsfc");
//    vec.push_back("/home/red/test/test/123");
//    vec.push_back("/home/red/test/test/main.o");

//    cout<<ji.open_work(vec)<<endl;

//    cout<<"asdhasdj"<<endl;
//    cout<<"asdhasdj"<<endl;

}

Widget::~Widget()
{
    delete ui;
}

