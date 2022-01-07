#ifndef MYBTN_H
#define MYBTN_H

#include <QWidget>
#include <QPushButton>
/*
 * 快捷键
 *注释  ctrl + /
 *运行 ctrl+r
 * 编译 ctrl + b
 * 字体缩放  ctrl + 鼠标滚轮
 * 查找 ctrl + f
 * 整行移动  ctrl+shift +up/down
 * 帮助文档  f1
 * 自动对齐  ctrl + i
 * 同名之间.h 和 .cpp 切换   f4
 *
 */
QT_BEGIN_NAMESPACE
namespace Ui { class myBtn; }
QT_END_NAMESPACE

class myBtn : public QWidget
{
    Q_OBJECT

public:
    myBtn(QWidget *parent = nullptr);
    ~myBtn();

private:
    Ui::myBtn *ui;
};
#endif // MYBTN_H
