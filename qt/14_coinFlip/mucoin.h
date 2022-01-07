#ifndef MUCOIN_H
#define MUCOIN_H

#include <QPushButton>
#include <QDebug>
#include <QTimer>
class MuCoin : public QPushButton
{
    Q_OBJECT
public:
    explicit MuCoin(QWidget *parent = nullptr);

    MuCoin(QString imgPath);

    QTimer *front2Back; //正面翻转为反面
    QTimer *back2Front; // 反面翻转为正面

    void changeFlag();  //用于翻转金币

    // 重写鼠标单击的事件,用于在翻转时,不处理此事件
    virtual void mousePressEvent(QMouseEvent *e);

    // 表示胜利标识
    bool isWin = false;
    // 记录coin的 位置信息
    int posX;
    int posY;
    bool flag; // 标记正反面
    // 用于记录翻转时 使用的图片信息
    int min=1;
    int max=8;
    // 记录当前是否正在进行翻转的动作
    bool isAnimation=false;
signals:

};

#endif // MUCOIN_H
