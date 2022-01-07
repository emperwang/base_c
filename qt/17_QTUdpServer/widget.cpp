#include "widget.h"
#include "ui_widget.h"

Widget::Widget(QWidget *parent)
    : QWidget(parent)
    , ui(new Ui::Widget)
{
    ui->setupUi(this);
    // 窗口信息初始化
    setWindowTitle("UdpSender port 8888");

    // socket 创建
    udpScoket = new QUdpSocket(this);
    QHostAddress addr = QHostAddress("127.0.0.1");
    quint16 port = 8888;

    // 设置默认的本地绑定端口
    ui->lineEditBind->setText(QString::number(port));

    // 开始端口绑定
    connect(ui->btnBind,&QPushButton::clicked,[=](){
       // 获取端口
        quint16 port = ui->lineEditBind->text().toUInt();
        // 地址绑定
        udpScoket->bind(addr,port);

        // 绑定socket的接收事件
        connect(udpScoket,&QUdpSocket::readyRead,this,[=](){

            //显示等待读取的数据
            qint64 size =  udpScoket->pendingDatagramSize();
            if(size == -1)
            {
                QMessageBox::information(nullptr,"info","no available data to read");
                return ;
            }
            // 读取所有的数据 并显示
            // 待优化, 如果数据量太大,可能会出问题
            // 优化为,分批次读取大数据
            char buf[size];
            QHostAddress addr;
            quint16 port;
            qint64 readlen = udpScoket->readDatagram(buf,size,&addr,&port);
            QString str = QString("read data length: %1").arg(readlen);
            qDebug()<< str;

            // 把读取的数据显示出来
            QString readData(buf);
            ui->textRead->append(QString("[%1:%2]: %3").arg(addr.toString()).arg(port).arg(readData));
        });
    });

    // 设置默认的对端地址
    ui->lineEditIp->setText("127.0.0.1");
    ui->lineEditPort->setText("9999");

    // 绑定发送按钮的发送事件
    connect(ui->btnSend,&QPushButton::clicked, this,[=](){
        if(udpScoket == nullptr || !udpScoket->isValid())
        {
            QMessageBox::information(nullptr,"Info","client not available");
            return;
        }

        // 获取要发送消息的 ip  port
        QString ip = ui->lineEditIp->text();
        QString port = ui->lineEditPort->text();
        if(ip.isNull() || ip.isEmpty() || port.isNull() || port.isEmpty())
        {
            QMessageBox::information(nullptr,"Info","Please input avaliable ip and port");
            return;
        }
        QString toSend = ui->textWrite->toPlainText();
        if(toSend.isNull() || toSend.isEmpty())
        {
            QMessageBox::information(nullptr,"Info","Please input avaliable message");
            return;
        }
        udpScoket->writeDatagram(toSend.toUtf8(),QHostAddress(ip),port.toUInt());
        // 清空发送端
        ui->textWrite->clear();
    });

    // 绑定 关闭按钮
    connect(ui->btnClose,&QPushButton::clicked, this, [=](){
        this->close();
    });

}

Widget::~Widget()
{
    delete ui;
}

