#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include "qtminiLibrary.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 调用导出函数
    qDebug() << add(100,100);

    // 调用导出类
    QTMiniLibrary library;
    qDebug() << library.PI;
    qDebug() << library.sub(1000,200);
}

Widget::~Widget()
{
    delete ui;
}

