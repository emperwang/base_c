#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    dataBase =  QSqlDatabase::addDatabase("QMYSQL");
    dataBase.setPort(3306);
    dataBase.setHostName("localhost");
    dataBase.setUserName("root");
    dataBase.setPassword("admin");
    dataBase.setDatabaseName("ssm");
    if(!dataBase.open())
    {
        QMessageBox::warning(this,"Error", "open database error");
        return ;
    }

    tblMode = new QSqlTableModel(this);
    tblMode->setTable("user");

    ui->tableView->setModel(tblMode);

    tblMode->select();

    // 修改自豪
    tblMode->setHeaderData(0,Qt::Horizontal, "学号");
    tblMode->setHeaderData(1,Qt::Horizontal, "姓名");
    tblMode->setHeaderData(2,Qt::Horizontal, "年龄");
    tblMode->setHeaderData(3,Qt::Horizontal, "地址");

    // 设置mode的编辑模式为 手动提交
    tblMode->setEditStrategy(QSqlTableModel::OnManualSubmit);

    // 设置view中的数据 不可以修改
    //ui->tableView->setEditTriggers(QAbstractItemView::NoEditTriggers);

    // 提交操作
    connect(ui->btnCommit, &QPushButton::clicked,this,[=](){
        bool submitRet = tblMode->submitAll();
        if(!submitRet)
        {
            QMessageBox::critical(this,"Commit Error", "commit errir");
        }
    });
    // 回滚操作
    connect(ui->btnRollBack, &QPushButton::clicked,this,[=](){
        tblMode->revertAll();
    });
}

Widget::~Widget()
{
    delete ui;
}

// 通过名字来绑定 槽函数
// 添加记录
void Widget::on_btnAdd_clicked()
{
    // 生成一个新的 record,用于存储要添加的记录
    QSqlRecord  record = tblMode->record();
    int index = tblMode->rowCount();
    //用于添加记录
    tblMode->insertRecord(index, record);
}


// 删除记录
void Widget::on_btnDelete_clicked()
{
    // 获取选中的记录
    QItemSelectionModel *selectMode = ui->tableView->selectionModel();
    //开始删除
    if(selectMode == nullptr)
    {
        QMessageBox::information(this,"info","please select record that you want to delete");
        return;
    }

    // 获取选中的行的 index
    QModelIndexList indexList =  selectMode->selectedRows();

    for(int i=0;i<indexList.size();i++)
    {
        QModelIndex idx = indexList.at(i);
        tblMode->removeRow(idx.row());
    }
}

void Widget::on_btnQuery_clicked()
{
    // 获取要查找的 用户名
    QString name = ui->lineEdit->text();
    if(name.isNull() || name.isEmpty())
    {
        QMessageBox::information(this,"info","Please input valid username");
        return;
    }

    QString fileter = QString("name='%1'").arg(name);

    tblMode->setFilter(fileter);
    tblMode->select();
}
