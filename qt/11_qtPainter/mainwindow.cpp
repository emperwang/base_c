#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置单击按钮,让图片进行移动
    connect(ui->pushButton,&QPushButton::clicked,[&](){
        posX+=20;
        if(posX > this->width())
        {
            posX = 0;
        }
        update();
    });

    // 使用定时器让图片移动
    QTimer *timer = new QTimer(this);
    timer->setInterval(2000);
    connect(timer,&QTimer::timeout,[&](){
        posX+=20;
        if(posX > this->width())
        {
            posX = 0;
        }
        update();
    });
    timer->start();
}

// 画图事件
void MainWindow::paintEvent(QPaintEvent *event)
{
    // painter 基本使用
    QPainter *painter = new QPainter(this);
    //baseDraw(painter);

    // painter 高级使用

    // painter 画图片
    painter->drawPixmap(QPoint(posX,0),QPixmap(":/Luffy.png"));

    painter->end();

}

void MainWindow::highPaint(QPainter *painter)
{
    painter->drawEllipse(QPoint(50,50),50,50);
    // 抗锯齿能力设置, 会让画出来的图画更清晰
    painter->setRenderHint(QPainter::Antialiasing);
    painter->drawEllipse(QPoint(150,50),50,50);
}

void MainWindow::painterMove(QPainter *painter)
{
    painter->drawRect(QRect(QPoint(50,50),QPoint(100,100)));
    // 让画笔进行了移动, 所以坐标一样的 矩形,画出的位置不一样
    painter->translate(QPoint(100,0));
    painter->drawRect(QRect(QPoint(50,50),QPoint(100,100)));
    //记录了一次位置,这样当需要时,可以随时restore回来
    painter->save();
    painter->drawRect(QRect(QPoint(100,100),QPoint(100,100)));
    painter->restore();
}

void MainWindow::baseDraw(QPainter *painter)
{
    // 1. 画线
    painter->drawLine(QPoint(0,0),QPoint(100,100));

    // 设置画笔颜色
    QPen pen = QPen(QColor(255,0,0));
    pen.setWidth(1);
    pen.setStyle(Qt::DashLine);
    painter->setPen(pen);

    // 设置画刷颜色
    QBrush brush = QBrush(Qt::green);
    painter->setBrush(brush);
    // 2. 画圆
    painter->drawEllipse(QPoint(100,100),50,50);

    // 3. 画矩形
    painter->drawRect(QRect(QPoint(50,50),QPoint(70,70)));
}

MainWindow::~MainWindow()
{
    delete ui;
}

