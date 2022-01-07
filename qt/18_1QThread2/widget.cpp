#include "widget.h"
#include "ui_widget.h"
#include <QDebug>
#include <QThread>

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    setFixedSize(416,327);

    setWindowTitle("QThread2");

    myThread = new MyQThread;   //  这里不可以设置父类
    thread = new QThread(this);

    // 把线程处理类和线程 进行关联
    myThread->moveToThread(thread);

    // 监听线程的timeout事件
    connect(myThread, &MyQThread::threadTimeoutSingal,this,[=](){
        static int count=1;
        ui->lcdNumber->display(QString::number(++count));;
    });

    //监听开始按钮
    connect(ui->btnStart,&QPushButton::clicked,this,[=](){
        qDebug() << "start thread";
        thread->start();

        // 发送开始信号
        emit this->startThreadSignal();
    });

    // 通过signal slot 来开始具体的处理线程
    // 这里是比较特殊的
    connect(this,&Widget::startThreadSignal,myThread,&MyQThread::sendTimeOut);

    // 监听 stop按钮
    connect(ui->btnStop, &QPushButton::clicked,this,[=](){
        qDebug()<< "stopping thread";
        myThread->setFlag(false);
        thread->quit();
        thread->wait();
    });

    //打印主线程
    qDebug()<< QThread::currentThread();


}

Widget::~Widget()
{
    delete ui;
}

