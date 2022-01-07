#include "myqthread.h"
#include <QThread>

MyQThread::MyQThread(QObject *parent) : QObject(parent)
{

}


void MyQThread::sendTimeOut()
{
    while (runFlag)
    {
        qDebug()<<QThread::currentThread();
        QThread::sleep(1);
        emit this->threadTimeoutSingal();

    }
}

void MyQThread::setFlag(bool flag )
{
    this->runFlag = flag;
}
