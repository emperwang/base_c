#ifndef MUPUSHBUTTON_H
#define MUPUSHBUTTON_H

#include <QPushButton>
#include <QDebug>
#include <QPropertyAnimation>
#include <QTimer>
#include "choosewidget.h"


class MuPushButton : public QPushButton
{
    Q_OBJECT
public:
    //explicit MuPushButton(QWidget *parent = nullptr);

    MuPushButton(QString normalImg, QString pressImg="");

    // pushButton的动画效果
    void zoom1();   // 向下弹
    void zoom2();   // 向上弹

    // pushButton的按下和松开的图片切换
    virtual void mousePressEvent(QMouseEvent *event);
    virtual void mouseReleaseEvent(QMouseEvent *event);

    void setButtonPicture(QString path);

private:
    QString normalImgPath;
    QString pressImgPath;


signals:


};

#endif // MUPUSHBUTTON_H
