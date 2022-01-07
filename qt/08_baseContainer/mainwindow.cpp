#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 设置默认显示的widget
    ui->stackedWidget->setCurrentIndex(1);

    // 连接按钮对应的事件处理,让其显示对应的信息
    connect(ui->btn_scroll,&QPushButton::clicked,this,[&](){
        ui->stackedWidget->setCurrentIndex(2);
    });

    connect(ui->btn_tool,&QPushButton::clicked,this,[&](){
        ui->stackedWidget->setCurrentIndex(0);
    });

    connect(ui->btn_tab,&QPushButton::clicked,this,[&](){
        ui->stackedWidget->setCurrentIndex(1);
    });
    // comboBox 设置
    ui->comboBox->addItem(QString("奔驰"));
    ui->comboBox->addItem(QString("奥迪"));
    ui->comboBox->addItem(QString("拖拉机"));

    connect(ui->btn_combo,&QToolButton::clicked,this,[&](){
        //ui->comboBox->setCurrentIndex(2);
        ui->comboBox->setCurrentText("拖拉机");
    });

    // 给label标签设置图片
    ui->lab_img->setPixmap(QPixmap(":/Image/butterfly1.png"));

    //给Qlable设置动图
    QMovie *move = new QMovie(":/Image/mario.gif");
    ui->lab_gif->setMovie(move);
    // 动图开始动起来
    move->start();


}

MainWindow::~MainWindow()
{
    delete ui;
}

