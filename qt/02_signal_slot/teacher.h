#ifndef TEACHER_H
#define TEACHER_H

#include <QObject>

class Teacher : public QObject
{
    Q_OBJECT
public:
    explicit Teacher(QObject *parent = nullptr);

signals:
    // 在这里定义信号, 信号只需要声明 不需要实现
    // 信号无返回值, 有参数, 表明可以重载
    void hungry();
    // 重载一个带参数的信号
    void hungry(QString foodName);

};

#endif // TEACHER_H
