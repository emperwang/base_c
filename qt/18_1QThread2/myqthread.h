#ifndef MYQTHREAD_H
#define MYQTHREAD_H

#include <QObject>
#include <QDebug>
class MyQThread : public QObject
{
    Q_OBJECT
public:
    explicit MyQThread(QObject *parent = nullptr);


    // 定义一个线程处理函数
    void sendTimeOut();

    void setFlag(bool);

private:
    bool runFlag = true;

signals:
    void threadTimeoutSingal();
};

#endif // MYQTHREAD_H
