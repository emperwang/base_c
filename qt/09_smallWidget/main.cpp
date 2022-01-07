#include "mainwindow.h"

#include <QApplication>

/*
 *  自定义控件类
 */
int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    return a.exec();
}
