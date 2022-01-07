#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    id1 = startTimer(1000); // 开始计时器1
    id2 = startTimer(2000); // 开启计时器2, 单位ms

    // 利用timer类来创建定时器
    QTimer *timer = new QTimer(this);
    timer->setInterval(500);
    connect(timer,&QTimer::timeout,[&](){
        static int num4=0;
        ui->label_4->setText(QString::number(num4++));
    });
    timer->start();
    connect(ui->btn,&QPushButton::clicked,[=](){
        static bool flag = false;
        if(!flag)
        {
            timer->stop();
            ui->btn->setText("开始");
            flag = true;
        }else {
            timer->start();
            ui->btn->setText("暂停");
            flag = false;
        }
    });

    // 事件过滤器的使用
    // 1. 给组件设置过滤器
    // 2. 重写eventFilter函数
    // 给组件设置过滤器
    ui->label->installEventFilter(this);


}

    // 重写eventFilter函数
bool MainWindow::eventFilter(QObject *obj, QEvent *e)
{
    // 拦截指定组件的指定事件
    // 在这里是拦截 obj组件的 鼠标按下事件
    if(obj == ui->label && e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent * ev = static_cast<QMouseEvent*>(ev);
        QString str = QString("eventFilter, 鼠标按下:x=%1, y=%2, globalX=%3,globalY=%4").arg(ev->x()).arg(ev->y())
                                                                .arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
    return QWidget::eventFilter(obj,e);
}

void MainWindow::timerEvent(QTimerEvent *event)
{
    if(event->timerId() == id1)
    {
        static int num1 = 0;
        ui->label_2->setText(QString::number(num1++));
    }
    if(event->timerId() == id2)
    {
        static int num2=0;
        ui->label_3->setText(QString::number(num2++));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

