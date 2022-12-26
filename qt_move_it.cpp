#include "qt_move_it.h"

qt_move_it::qt_move_it(QWidget *parent)
    : QWidget{parent}
{
    v_parent=parent;
}

void qt_move_it::set_pos(QPoint pos)
{
    pos_origin = pos;
}

void qt_move_it::set_space(int space)
{
    v_space = space;
}

void qt_move_it::add_wid(QWidget *wid)
{
    vec.push_back(wid);
}

void qt_move_it::set_wid_vec(QVector<QWidget *> vec_wid)
{
    for(int i=0;i<vec.size();i++)
    {
        delete vec[i];
    }

    vec = vec_wid;
}

void qt_move_it::set_hori(QPoint pos)
{
    for(auto &a:vec)
    {
        a->move(pos);
        //累加距离
        pos = QPoint(a->width() + v_space + pos.x(),pos.y());
    }
}

void qt_move_it::set_vert()
{
    QPoint pos;
    for(auto &a:vec)
    {
        pos = QPoint(v_parent->width()/2 - a->width()/2,
                   a->height() + v_space + pos.y());//累加距离
        a->move(pos);
    }
}

void qt_move_it::set_vert(QPoint pos)
{
    for(auto &a:vec)
    {
        a->move(pos);
        pos = QPoint(pos.x(),
                   a->height() + v_space + pos.y());//累加距离
    }
}

void qt_move_it::set_hide()
{
    for(auto &a:vec)
    {
        a->hide();
    }
}

void qt_move_it::set_show()
{
    for(auto &a:vec)
    {
        a->show();
    }
}

void qt_move_it::set_clear()
{
    for(int i=0;i<vec.size();i++)
    {
        delete  vec[i];
    }
}

int qt_move_it::get_count_high()
{
    int count=0;
    for(auto &a:vec)
    {
        count += a->height();
    }
    return count;
}
