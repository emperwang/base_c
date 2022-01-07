#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include "teacher.h"
#include "student.h"
#include <QDebug>

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:

    Teacher * tz;
    Student * st;

    void classIsOver();
};
#endif // WIDGET_H
