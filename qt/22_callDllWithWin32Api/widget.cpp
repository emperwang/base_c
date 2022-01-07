#include "widget.h"
#include "ui_widget.h"
#include "miniLib.h"
#include <QDebug>

typedef void (*PFunc)(wchar_t *);
Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 动态加载dll库
    HMODULE hModule = ::LoadLibraryW(_T("E:/code-workSpace/project-C/base-C/qt/22_callDllWithWin32Api/04_1_dllWithDef"));
    char buf[1024];
    ::GetCurrentDirectoryA(1024,buf);
    qDebug()<<buf;
    if(!hModule)
    {
        QMessageBox::information(this,"info","Load dll 04_1_dllWithDef error");
        return;
    }
    // 获取函数
    void * func;
    func= (void*)::GetProcAddress(hModule,"miniMsgBox");
    if(!func)
    {
        QMessageBox::information(this,"info","get miniMsgBox error");
        //FreeLibrary(hModule);
        return;
    }else
    {
        PFunc fun = (PFunc)func;
        fun(_T("Call from QT"));
        //FreeLibrary(hModule);
    }

    //  调用其中的全局变量
    int *gValue;
    gValue = (int *)GetProcAddress(hModule,"globalVal");
    qDebug() << *gValue;

    FreeLibrary(hModule);
}

Widget::~Widget()
{
    delete ui;
}

