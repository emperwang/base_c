#include "widget.h"
#include "ui_widget.h"
#include <QMessageBox>
#include <QDebug>
#include <windows.h>
#include <tchar.h>

typedef void (*PFunc)(wchar_t *);
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 使用qLibrary 加载dll动态库
    PFunc fun;
    QLibrary lib("04_1_dllWithDef");
    if(lib.load())
    {
        fun = (PFunc) lib.resolve("miniMsgBox");
        if(!fun)
        {
            QMessageBox::information(this,"info","Load func error");
            return;
        }else
        {
            // 调用函数
            fun(L"Call from QLibrary");
        }
    }else
    {
        QMessageBox::information(this,"info","Load library error");
    }

    // 调用dll中声明 的全局变量
    int *gValue;
    gValue = (int *)lib.resolve("globalVal");
    qDebug() << *gValue;

    // 调用导出类
    // 这里的dll库 使用的是 vs 编译的,可能编译器不同,导致的连接失败.
   // CMath math;


}

Widget::~Widget()
{
    delete ui;
}

