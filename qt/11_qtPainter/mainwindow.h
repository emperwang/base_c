#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QTimer>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();


    virtual void paintEvent(QPaintEvent *event);
    void baseDraw(QPainter *painter);
    void painterMove(QPainter *painter);
    void highPaint(QPainter *painter);

    // 设置图片的初始x位置
    int posX=0;
private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
