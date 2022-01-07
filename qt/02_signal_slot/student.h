#ifndef STUDENT_H
#define STUDENT_H

#include <QObject>

class Student : public QObject
{
    Q_OBJECT
public:
    explicit Student(QObject *parent = nullptr);

    void treat();

signals:
    // 在这里定义信号
public slots:
    // public 或者 全局 以及 slots里面定义slot 槽处理函数
    // 重载一个带参数的slot槽函数
    void treat(QString foodName);
};

#endif // STUDENT_H
