#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->btn_get,&QPushButton::clicked,[&](){
        qDebug()<< ui->widget->getNum();
    });

    connect(ui->btn_set,&QPushButton::clicked,[&](){
        ui->widget->setNum(50);
    });
}

MainWindow::~MainWindow()
{
    delete ui;
}

