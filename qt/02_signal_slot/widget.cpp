#include "widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
{

    this->st = new Student(this);
    this->tz = new Teacher(this);

    // 信号连接
    //connect(this->tz,&Teacher::hungry, this->st, &Student::treat);

    // 设置带参数的信号以及槽处理函数的连接
    // 设置函数指针
    void (Teacher:: *teacherSignal)(QString) =&Teacher::hungry;
    void (Student:: *studentSlot)(QString) = &Student::treat;
    connect(this->tz, teacherSignal, this->st, studentSlot);


    // 信号触发
    classIsOver();

    // 添加一个按钮,通过按钮来触发信号
    QPushButton *btn = new QPushButton(this);
    btn->setText("下课了");
    this->resize(400,500);
    btn->show();
    // 点击事件 和  classIsOver连接
    //connect(btn,&QPushButton::clicked, this, &Widget::classIsOver);

    void(Teacher::*teacherSignal2)() = &Teacher::hungry;
    void (Student:: *studentSlot2)() = &Student::treat;
    connect(this->tz,teacherSignal2,this->st, studentSlot2);
    // 信号和信号连接
    connect(btn, &QPushButton::clicked, this->tz, teacherSignal2);

    // 信号断开操作
    //disconnect(this->tz,teacherSignal2,this->st, studentSlot2);

    /**
     扩展:
     1. 信号是可以连接信号的
     2.一个信号可以连接多个槽函数
     3.多个信号 可以连接 同一个槽函数
     4.信号和参函数的参数 必须类型 一一对应
     5.信号和槽的 参数个数是不是要一致?
        信号的参数可以 多于 槽函数的个数
     */
    // QT4之前的 信号和槽的连接方式
    //connect(tz,SIGNAL(hungry()), st, SLOT((treat())));

    // lambda 表达式
    // 通过lambda表示修改上面的btn按钮的 text
    [=](){
        btn->setText("set by lambda: 下课");
    }();

    // lambda返回值
    int a = []()->int{return 100;}();
    qDebug()<<"get value from lambda ";


    // 添加一个按钮,通过lambda表达式 设置其可以关闭窗口
    QPushButton *btns = new QPushButton("close",this);
    btns->move(100,0);
    connect(btns, &QPushButton::clicked, [=](){
        this->close();
    });
}


void Widget::classIsOver(){
    //emit this->tz->hungry();
    // 发送一个带参数的 信号
    emit this->tz->hungry("宫保鸡丁");
}

Widget::~Widget()
{
}

