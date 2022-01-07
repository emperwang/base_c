#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);

    // 1. 设置标题
    setWindowTitle("TcpServer");
    // 2. 设置icon
    pix.load(":/mainBg1.png");
    pix = pix.scaled(pix.width()*0.4, pix.height()*0.4);
    setWindowIcon(QIcon(pix));

    // 3. server端监听
    this->server = new QTcpServer(this);
    this->server->setMaxPendingConnections(100);
    int port = 19999;
    QHostAddress address = QHostAddress(QHostAddress::LocalHost);
    this->server->listen(address,port);

    // 4. 显示ip和port
    ui->line_ip->setText(address.toString());
    ui->line_ip->setReadOnly(true);

    ui->line_port->setText(QString::number(port));
    ui->line_port->setReadOnly(true);
    if(ui->hosts->count() > 0)
    {
        ui->hosts->setCurrentIndex(1);
    }
    // 5.绑定 server 连接事件, 如果有连接则进行处理
    connect(server,&QTcpServer::newConnection,this,[=](){
        QTcpSocket *client =  server->nextPendingConnection();
        // 5.1 记录新连接的客户端
        this->clients.push_back(client);

        // 获取客户端的连接信息
        QString clientInfo = getClientInfo(client);
        clientMap.insert(clientInfo, client);
        ui->hosts->addItem(clientInfo);
        QString cliText = QString("New client: %1").arg(clientInfo);
        ui->textRead->append(cliText);

        // 6. 监听对应的客户端有 消息发送过来
        connect(client, &QTcpSocket::readyRead,this,[=](){
            // 开始处理数据读取事件
            QByteArray data = client->readAll();
            QString cliInfo = getClientInfo(client);
            QString toPrint = QString("receive from %1 : ").arg(cliInfo);
            ui->textRead->append(toPrint);
            ui->textRead->append(QString(data));
        });

        // 9. 监听socket连接断开的操作
        connect(client,&QTcpSocket::disconnected,this,[=](){
            QString cInfo = getClientInfo(client);
            int idx = ui->hosts->findText(cInfo);
            ui->hosts->removeItem(idx);
            QString str = QString("client %1 disconnect.").arg(cInfo);
            ui->textRead->append(str);
        });
    });

    // 7. 绑定发送消息的事件
    connect(ui->btn_send,&QPushButton::clicked,this,[=](){
        // 获取要发送的ip
        QString cip = ui->hosts->currentText();
        if(cip.isEmpty() || cip.isNull())
        {
            QMessageBox::information(nullptr,"info","No available client.");
            return;
        }
//        int idx = cip.indexOf(QChar(':'));
//        QString ip = cip.mid(0,idx);
        // 获取要发送的数据
        QString toSend = ui->textWrite->toPlainText();
        {
            if(toSend.isEmpty() || toSend.isNull())
            {
                QMessageBox::information(nullptr,"info","No available input.");
                return;
            }
        }
        // 获取要发送的客户端 client
        QMap<QString, QTcpSocket*>::iterator iter =  clientMap.find(cip);
        if(iter != clientMap.end())
        {
            QTcpSocket *cliSocket = iter.value();
            // 数据发送
            // todo 待优化的发送点
            cliSocket->write(toSend.toUtf8());

            // 情况发送text
            ui->textWrite->clear();
        }

    });

    // 8.断开连接的操作
    connect(ui->btn_disconnect,&QPushButton::clicked,this,[=](){
        // 获取要发送的ip
        QString cip = ui->hosts->currentText();
        if(cip.isEmpty() || cip.isNull())
        {
            return;
        }
        // 获取要发送的客户端 client
        QMap<QString, QTcpSocket*>::iterator iter =  clientMap.find(cip);
        if(iter != clientMap.end())
        {
            QTcpSocket *cliSocket = iter.value();
            QString strInfo = getClientInfo(cliSocket);
            QString str = QString("Client %1 disconnect..").arg(strInfo);
            int idx = ui->hosts->findText(strInfo);
            ui->hosts->removeItem(idx);
            ui->textRead->append(str);
            // 断开连接
            cliSocket->disconnect();
            cliSocket->close();
        }
    });
}

QString Widget::getClientInfo(QTcpSocket *client)
{
    QString cip = client->peerAddress().toString();
    qint16 port = client->peerPort();
    QString clientInfo = QString("%1:%2").arg(cip).arg(port);
    return clientInfo;
}

Widget::~Widget()
{
    delete ui;
}




