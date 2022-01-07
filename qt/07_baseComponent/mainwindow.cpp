#include "mainwindow.h"
#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    connect(ui->resBtnName,&QToolButton::clicked,this,[](){
        qDebug() << "btn click event";
    });

    connect(ui->ch1,&QCheckBox::stateChanged,this,[](int state){
        qDebug()<<"state: "<<state;
    });

    // listWidgetItem是listWidget中的显示控件
    //QListWidgetItem *widgeItem = new QListWidgetItem("锄禾日当午");
    //widgeItem->setTextAlignment(Qt::AlignHCenter);
    // 向listWidget中添加item
    //ui->listWidget->addItem(widgeItem);

    // 一次添加多个item到listwidget中
    QStringList list;
    list << "锄禾日当午"<<"汗滴禾下土"<<"谁知盘中餐"<<"粒粒皆辛苦";
    ui->listWidget->addItems(list);


    //treeWidget  树形控件
    ui->treeWidget->setHeaderLabels(QStringList()<<"英雄"<<"英雄介绍");
    QTreeWidgetItem *liItem = new QTreeWidgetItem(QStringList()<<"力量");
    QTreeWidgetItem *minItem = new QTreeWidgetItem(QStringList()<<"敏捷");
    QTreeWidgetItem *zhiItem = new QTreeWidgetItem(QStringList()<<"智力");
    ui->treeWidget->addTopLevelItem(liItem);
    ui->treeWidget->addTopLevelItem(minItem);
    ui->treeWidget->addTopLevelItem(zhiItem);

    //添加子控件
    QStringList heroLi;
    heroLi<<"刚被猪" << "前排坦克,能在吸收伤害的同时造成客观的范围输出";
    QTreeWidgetItem *li1 = new QTreeWidgetItem(heroLi);
    liItem->addChild(li1);

    // tableWidget 组件
    // 设置列数
    ui->tableWidget->setColumnCount(3);
    //设置列名
    ui->tableWidget->setHorizontalHeaderLabels(QStringList()<<"姓名"<<"性别"<<"年龄");

    // 设置行数
    ui->tableWidget->setRowCount(5);
    // 添加内容
    //ui->tableWidget->setItem(0,0,new QTableWidgetItem(QString("张飞")));
    QStringList nameList;
    nameList << "刘备" << "张飞"<<"关羽"<<"赵云"<<"木兰";

    QList<QString> sexList;
    sexList<<"男"<<"男"<<"男"<<"男"<<"女";
    for(int i=0;i<5; i++)
    {
        int col=0;
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString(nameList[i])));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString(sexList[i])));
        ui->tableWidget->setItem(i,col++,new QTableWidgetItem(QString(QString::number(i+18))));
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

