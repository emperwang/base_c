#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    setWindowTitle("QThread");

    setFixedSize(389,277);

    mythread = new MyThread(this);
    //监听线程的停止信号
    connect(mythread, &MyThread::stopTimer,this,[=](){
        if(timer->isActive())
        {
            timer->stop();
        }
        // 然后停止线程
        mythread->setFlag(false);
        isStop = true;
    });
    timer = new QTimer(this);

    // 监听timer的超时信息,用于显示
    connect(timer,&QTimer::timeout,this, [=](){
        static int count = 0;
        count++;
        ui->lcdNumber->display(count);
    });

    // 监听开始按钮,然后开始线程
    connect(ui->btnStart,&QPushButton::clicked, [=](){
        qDebug() << "start thread";
        if(!isStop) // 没有被停止,才开始运行线程
        {
            mythread->start();
            // 同时开始定时器
            timer->start(500);
        }
    });

    connect(ui->btnClose,&QPushButton::clicked, this,[=](){this->close();});
}

Widget::~Widget()
{
    delete ui;
}

