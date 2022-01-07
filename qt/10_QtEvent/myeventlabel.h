#ifndef MYEVENTLABEL_H
#define MYEVENTLABEL_H

#include <QLabel>
#include <QDebug>
#include <QMouseEvent>

class MyEventLabel : public QLabel
{
    Q_OBJECT
public:
    explicit MyEventLabel(QWidget *parent = nullptr);

    virtual void mouseMoveEvent(QMouseEvent *ev) override;

    virtual void mousePressEvent(QMouseEvent *ev) override;

    virtual void mouseReleaseEvent(QMouseEvent *ev) override;

    virtual void enterEvent(QEvent *event) override;

    virtual void leaveEvent(QEvent *event) override;

    // 事件分发器,也可以作为事件过滤器使用
    // 本处演示 事件过滤器的使用

    bool event(QEvent *e) override;

signals:

};

#endif // MYEVENTLABEL_H
