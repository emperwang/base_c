#include "myeventlabel.h"

MyEventLabel::MyEventLabel(QWidget *parent) : QLabel(parent)
{
    //开启鼠标追踪事件
    setMouseTracking(true);
}
void MyEventLabel::mouseMoveEvent(QMouseEvent *ev)
{
    QString str = QString("鼠标移动:x=%1, y=%2, globalX=%3,globalY=%4").arg(ev->x()).arg(ev->y())
                                                            .arg(ev->globalX()).arg(ev->globalY());
    qDebug() << str;
}

void MyEventLabel::mousePressEvent(QMouseEvent *ev)
{
    //只是打印鼠标左键事件
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标按下:x=%1, y=%2, globalX=%3,globalY=%4").arg(ev->x()).arg(ev->y())
                                                                .arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

bool MyEventLabel::event(QEvent *e)
{
    if(e->type() == QEvent::MouseButtonPress)
    {
        QMouseEvent *ev = static_cast<QMouseEvent*>(e);
        QString str = QString("EVENT 事件分发中处理, 鼠标按下:x=%1, y=%2, globalX=%3,globalY=%4").arg(ev->x()).arg(ev->y())
                                                                .arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
        return true;
    }
    //其他事件交由父类进行处理
    return QLabel::event(e);
}

void MyEventLabel::mouseReleaseEvent(QMouseEvent *ev)
{
    //只是打印鼠标左键事件
    if(ev->button() == Qt::LeftButton)
    {
        QString str = QString("鼠标释放:x=%1, y=%2, globalX=%3,globalY=%4").arg(ev->x()).arg(ev->y())
                                                                .arg(ev->globalX()).arg(ev->globalY());
        qDebug() << str;
    }
}

void MyEventLabel::enterEvent(QEvent *event)
{
    //qDebug() << "鼠标进入事件";
}

void MyEventLabel::leaveEvent(QEvent *event)
{
    //qDebug() << "鼠标离开事件";
}
