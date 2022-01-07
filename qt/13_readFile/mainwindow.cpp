#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    //单击按钮弹出打开文件对话框
    connect(ui->btn_open,&QPushButton::clicked,[=](){
        QString path = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\Sparks\\Desktop");
        ui->lineEdit->setText(path);

        //打开文件,并把文件内容读取到 textEdit中
        QFile file(path);
        file.open(QIODevice::ReadOnly);
        // 这是一般的默认读取方式
        //QByteArray array = file.readAll();
        //ui->textEdit->setText(array);

        // 使用的特定的编码器解码后,在进行输出
        QByteArray array = file.readAll();
        QTextCodec *codec = QTextCodec::codecForName("UTF-8");
        ui->textEdit->setText(codec->toUnicode(array));

    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

