#include "widget.h"

#include <QApplication>

/*
 * 需求: 老师类  学生类
 *  老师会触发 hungry 信号, 学生接收到信号后会处理
 */

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    Widget w;
    w.show();
    return a.exec();
}
