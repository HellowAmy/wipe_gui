#include "widget.h"
#include "wid_main.h"

#include <QApplication>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

#if 0
    Widget w;
    w.show();
#else
    wid_main k;
    k.show();
#endif

    return a.exec();
}
