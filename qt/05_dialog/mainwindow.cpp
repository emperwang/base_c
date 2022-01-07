#include "mainwindow.h"
#include "ui_mainwindow.h"
#include <QDialog>
#include <QMessageBox>
#include <QColorDialog>
#include <QFileDialog>
#include <QFontDialog>
#include <QColor>
#include <QDebug>
#include <QFont>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // 重新设置一下大小
    resize(600,400);

    //打开一个对话框
    connect(ui->actionopen,&QAction::triggered,[=](){

        //先创建一个模态的对话框
        QDialog dialog(this);
        dialog.resize(200,100);
        //dialog.exec();

        // 创建一个非模态的对话框
        /*QDialog *dia = new QDialog(this);
        dia->resize(200,100);
        dia->setAttribute(Qt::WA_DeleteOnClose);
        dia->show();*/

        // message box
        // 错误
        //QMessageBox::critical(this,"critical","警告");

        // 信息提示
        //QMessageBox::information(this,"info", "information");

        // 警告
        //QMessageBox::warning(this,"warn","this is warning");

        //提问
        //QMessageBox::question(this,"question","需要关闭吗?");

        // 替换默认的选择按钮
        //QMessageBox::question(this,"question","需要关闭吗?",QMessageBox::Yes|QMessageBox::Cancel);

        // 指定默认的选择按钮
        //QMessageBox::question(this,"question","需要关闭吗?",QMessageBox::Yes|QMessageBox::Cancel,QMessageBox::Cancel);

        // 其他标准对话框
        // 颜色对话框
        //QColor color = QColorDialog::getColor(QColor(0,0,0), this);
        //qDebug() << "r "<<color.red() << "g " << color.green() << " b"<<color.blue();

        //文件对话框
        // 参数一: 父对话框  参数二: 标题, 参数三: 打开路径, 参数四: 过滤器
        //QString filePath = QFileDialog::getOpenFileName(this,"打开文件","C:\\Users\\Sparks\\Desktop","(*)");
        //qDebug() << "file path: " <<filePath;

        //字体对话框
           bool flag;
        QFont font = QFontDialog::getFont(&flag,this);
        qDebug() << "font: "<<font.family() << "Size: "<<font.style();
    });

}

MainWindow::~MainWindow()
{
    delete ui;
}

