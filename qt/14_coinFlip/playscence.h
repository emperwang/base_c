#ifndef PLAYSCENCE_H
#define PLAYSCENCE_H

#include <QMainWindow>
#include <QPainter>
#include <QDebug>
#include <QMenuBar>
#include <QMenu>
#include <QTimer>
#include <QLabel>
#include <QPropertyAnimation>
#include "mupushbutton.h"
#include "mucoin.h"
#include"dataconfig.h"
class PLayScence : public QMainWindow
{
    Q_OBJECT
public:
    explicit PLayScence(QWidget *parent = nullptr);
    PLayScence(int level);

    // 重写painterEvent进行背景设置
virtual void paintEvent(QPaintEvent *event);

    // 胜利标志
    bool isWin;

private:
    int levelNum;
    // 创建一个 二维数组,记录此关卡对应的数据
    int gameArray[4][4];

    MuCoin *coins[4][4];

signals:
    void playScenceBack();
};

#endif // PLAYSCENCE_H
