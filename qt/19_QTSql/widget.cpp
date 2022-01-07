#include "widget.h"
#include "ui_widget.h"

// test database connect and base query
void dbConnect()
{
    // 打印所有可用的驱动
    QStringList drivers = QSqlDatabase::drivers();
    qDebug() << drivers;
    bool avail = QSqlDatabase::isDriverAvailable("QMYSQL");
    qDebug() << avail;
}


Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    //dbConnect();

    // 开始连接数据库
    msql1 = QSqlDatabase::addDatabase("QMYSQL");
    msql1.setHostName("localhost");
    msql1.setUserName("root");
    msql1.setPort(3306);
    msql1.setPassword("admin");
    msql1.setDatabaseName("ssm");
    bool isOpen = msql1.open();
    qDebug() << isOpen;
//    insertOne();
//    updateByName();
//    queryAll();
//    deleteByName();
//    queryAll();



}

void Widget::queryAll()
{
    QSqlQuery query;
    // prepareStatement
    query.prepare("select * from user");
    query.exec();
    while (query.next())
    {
        int id = query.value(0).toInt();
        QString uname = query.value(1).toString();
        int age = query.value(2).toInt();
        QString addr = query.value(3).toString();
        //qDebug()<< QString("id: %1, name: %2, age: %3, address: %4").arg(QString::number(id)).arg(uname).arg(QString::number(age)).arg(addr);

        QSqlRecord rec =  query.record();
        //qDebug() <<  QString("record counts:%1").arg(rec.count());
        QSqlField idField = rec.field("id");
        qint32 id1 = idField.value().toInt();
        QString name2 =  rec.field("name").value().toString();
        qint32 age2 = rec.field("age").value().toInt();
        QString addr2 = rec.field("address").value().toString();

        qDebug()<< QString("id2: %1, name2: %2, age2: %3, address2: %4")
                   .arg(QString::number(id1)).arg(name2).arg(QString::number(age2)).arg(addr2);
    }

}

void Widget::insertOne()
{
    QSqlQuery query;
    QString sql = "insert into user(name,age,address) values(?,?,?)";
    query.prepare(sql);

    query.bindValue(0,"wangwu");
    query.bindValue(1,40);
    query.bindValue(2,"nj");
    query.exec();

    QSqlQuery query2;
    QString sql2 = "insert into user(name,age,address) values(:name,:age,:addr)";
    query2.prepare(sql2);
    query2.bindValue(":name","zhaoliu");
    query2.bindValue(":age",90);
    query2.bindValue(":addr","gz");
    query2.exec();
}

void Widget::updateByName()
{
    QSqlQuery updateSql;
    QString sql2 = "update user set address = :addr where name = :name";
    updateSql.prepare(sql2);
    updateSql.bindValue(":addr", "CN_GD_GZ");
    updateSql.bindValue(":name", "zhaoliu");
    updateSql.exec();
}

void Widget::deleteByName()
{
    QSqlQuery deleteSql;

    QString sql = "delete from user where name = :name";
    deleteSql.prepare(sql);

    deleteSql.bindValue(":name", "zhaoliu");
    deleteSql.exec();

}


Widget::~Widget()
{
    delete ui;
}

