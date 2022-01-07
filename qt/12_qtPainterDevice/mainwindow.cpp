#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

void usePixMapDevice()
{
    // 这里把画图设备设置为 QPixmap
    QPixmap pixMap(300,300);

    // 设置背景色
    pixMap.fill(Qt::white);

    QPainter painter(&pixMap);
    painter.setPen(QPen(Qt::cyan));
    painter.drawEllipse(QRect(QPoint(100,100),QPoint(50,50)));
    // 保存最后的结果
    pixMap.save("E:/code-workSpace/project-C/base-C/qt/pixMap.png");
}

void useQImageDevice()
{
    // 使用QImage 使用画图设备
    QImage image(300,400,QImage::Format_RGB32);
    // 设置背景色
    image.fill(Qt::cyan);

    QPainter *painter2 = new QPainter(&image);
    painter2->setPen(QPen(Qt::red));
    painter2->drawEllipse(QRect(QPoint(100,100),QPoint(50,50)));
    // picture 记录画图记录
    image.save("E:/code-workSpace/project-C/base-C/qt/image.png");

    delete painter2;
}

void MainWindow::usePicture()
{
    // save picture
    QPicture pic = QPicture();
    QPainter *painter = new QPainter(&pic);
    painter->setPen(QPen(Qt::green));
    painter->drawEllipse(QPoint(100,100),50,50);

    painter->end();
    pic.save("./pic.zt");

    // load picture and print

    QPicture picLoad = QPicture();
    picLoad.load("./pic.zt");
    QPainter* paint = new QPainter(this);
    paint->drawPicture(QPoint(100,100),picLoad);

    paint->end();
}

void MainWindow::paintEvent(QPaintEvent *event)
{
    usePixMapDevice();
    useQImageDevice();
    usePicture();
}

MainWindow::~MainWindow()
{
    delete ui;
}

