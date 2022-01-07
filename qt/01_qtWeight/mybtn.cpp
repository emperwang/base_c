#include "mybtn.h"
#include "ui_mybtn.h"
#include <QString>

myBtn::myBtn(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::myBtn)
{
    ui->setupUi(this);
    // 创建一个按钮

    QPushButton *btn  = new QPushButton;
    btn->setParent(this);
    btn->setText(QString("first btn"));
    btn->show();

    // 设置窗口大小
    resize(400,500);
    // 设置窗口固定大小
    setFixedSize(400,500);
    // 设置窗口的标题
    setWindowTitle("第一个窗口");

    // 创建第二个窗口
    QPushButton *bt2 = new QPushButton("第二个按钮", this);
    // 设置btn的位置
    bt2->move(100,200);

    // 信号 和 槽函数 处理
    // 参数1: 信号发送者   参数2: 发送的信号(函数地址)
    // 参数3: 参数接收者    参数4: 信号处理函数(slot, 函数地址)
    connect(btn, &QAbstractButton::clicked, this, &QWidget::close);
}

myBtn::~myBtn()
{
    delete ui;
}

