#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include "myqthread.h"
#include <QThread>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();


signals:
    void startThreadSignal();

private:
    Ui::Widget *ui;
    MyQThread *myThread = nullptr;
    QThread *thread = nullptr;
};
#endif // WIDGET_H
