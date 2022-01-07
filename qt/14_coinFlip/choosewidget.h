#ifndef CHOOSEWIDGET_H
#define CHOOSEWIDGET_H

#include <QMainWindow>
#include <QSound>
#include "mupushbutton.h"
#include "playscence.h"

class PLayScence;
class ChooseWidget : public QMainWindow
{
    Q_OBJECT
public:
    explicit ChooseWidget(QWidget *parent = nullptr);


protected:
    virtual void paintEvent(QPaintEvent *event);

private:
    PLayScence *scence = nullptr;

//    MuPushButton *btnBack = nullptr;
signals:
    // 定义一个信号,用于通知 主窗口, scence进行了返回
    void chooseScenceBack();
};

#endif // CHOOSEWIDGET_H
