#include "mythread.h"

MyThread::MyThread(QObject *parent) : QThread(parent)
{

}

void MyThread::run()
{
    while(runFlag)
    {
        //打印当前线程信息
        qDebug() << QThread::currentThread();
        sleep(10);
        qDebug()<<"sending stop timer singal";
        emit stopTimer();
    }
}


void MyThread::setFlag(bool flag)
{
    qDebug() << QString("changing flag: %1").arg(flag);
    this->runFlag = flag;
    if(!flag)
    {
        qDebug()<<"quit...";
        quit();
        wait();
    }
}

