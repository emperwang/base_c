#include "mucoin.h"

MuCoin::MuCoin(QWidget *parent) : QPushButton(parent)
{

}

// 自定义的构造
MuCoin::MuCoin(QString imgPath)
{
    // 1. 设置背景
    QPixmap pix;
    bool ret = pix.load(imgPath);
    if(!ret)
    {
        QString res = QString("load image: %1 error").arg(imgPath);
        qDebug()<<res;
    }

    // 2. 设置大小
    setFixedSize(pix.width(),pix.height());
    // 3. 设置样式
    setStyleSheet("QPushButton{border: 0px;}");

    // 4.设置Icon
    setIcon(QIcon(pix));
    setIconSize(QSize(pix.width(),pix.height()));

    // 5. 初始化qtimer 信息
    front2Back = new QTimer(this);
    back2Front = new QTimer(this);

    // 7.监听qtimer的信息,用于翻转信息
    connect(front2Back,&QTimer::timeout,[=](){
        QString str = QString(":/res/Coin000%1").arg(this->min++);
        QPixmap pix;
        pix.load(str);
        this->setFixedSize(pix.width(),pix.height());
        this->setStyleSheet("QPushButton{border:0px;}");
        this->setIcon(QIcon(pix));
        this->setIconSize(QSize(pix.width(),pix.height()));

        if(this->min > this->max){
            this->min = 1;
            this->isAnimation = false;
            front2Back->stop();
        }
    });

    // 反面翻正面
    connect(back2Front,&QTimer::timeout,[=](){
       QString str = QString(":/res/Coin000%1").arg(this->max--) ;
       QPixmap pix;
       pix.load(str);
       this->setFixedSize(pix.width(),pix.height());
       this->setStyleSheet("QPushButton{border: 0px;}");
       this->setIcon(QIcon(pix));
       this->setIconSize(QSize(pix.width(),pix.height()));

       if(this->max < this->min){
           this->max = 8;
           this->isAnimation = false;
           back2Front->stop();
       }
    });
}

// 6. flag翻转
void MuCoin::changeFlag()
{
    if(!flag) { // 反面翻转正面
        this->flag = true;
        this->isAnimation = true;
        back2Front->start(20);

    }else{ //正面翻转反面
        this->flag = false;
        this->isAnimation = true;
        front2Back->start(20);
    }
}


void MuCoin::mousePressEvent(QMouseEvent *e)
{
    // 当正在翻转 或者是 已经胜利,则忽略鼠标单击事件
    if(isAnimation || isWin)
    {
        return;
    }else{
        QPushButton::mousePressEvent(e);
    }
}

