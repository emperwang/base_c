#ifndef MYTHREAD_H
#define MYTHREAD_H

#include <QThread>
#include <QDebug>

class MyThread : public QThread
{
    Q_OBJECT
public:
    explicit MyThread(QObject *parent = nullptr);

    void setFlag(bool);

protected:
    void run() override;

private:
    volatile bool runFlag = true;


signals:
    // 定义一个singal, 用于测试
    void stopTimer();
};

#endif // MYTHREAD_H
