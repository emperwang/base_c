#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 设置 窗口信息
    setWindowTitle("TcpClient");
    pix.load(":/Coin0008.png");
    setWindowIcon(QIcon(pix));

    // 设置默认的服务器地址
    ui->line_ip->setText("127.0.0.1");
    ui->line_port->setText(QString::number(19999));

    // 客户端初始化
    client = new QTcpSocket(this);
    // 绑定开始连接的操作
    connect(ui->btn_connect,&QPushButton::clicked, this,[=](){
        // 获取ip地址
        QHostAddress addr = QHostAddress(ui->line_ip->text());
        qint16 port = ui->line_port->text().toInt();
        client->connectToHost(addr, port);
    });


    // 监听连接成功的事件
    connect(client, &QTcpSocket::connected,this,[=](){
        QString str = QString("客户端连接 %1 成功...").arg(ui->line_ip->text());
        ui->text_read->append(str);

        // 监听断开操作
        connect(client,&QTcpSocket::disconnected,this,[=](){
            QString cip = client->peerAddress().toString();
            qint16 port = client->peerPort();
            QString clientInfo = QString("客户端:%1:%2 断开连接..").arg(cip).arg(port);
            ui->text_read->append(clientInfo);
        });
    });

    // 绑定可以接收数据的事件
    connect(client, &QTcpSocket::readyRead,this,[=](){
        // 有数据过来
        QByteArray arr = client->readAll();
        QString str = QString("receive from server: %1").arg(QString(arr));
        ui->text_read->append(str);
    });

    // 绑定数据发送
    connect(ui->btn_send, &QPushButton::clicked,[=](){
        // 获取数据
        QString toSend = ui->text_write->toPlainText();
        // 发送数据
        client->write(toSend.toUtf8());
        // 清空发送空间
        ui->text_write->clear();
    });

    // 断开连接
    connect(ui->btn_disconnect,&QPushButton::clicked,[=](){
        client->disconnect() ;
        client->close();
    });

}

Widget::~Widget()
{
    delete ui;
}
























