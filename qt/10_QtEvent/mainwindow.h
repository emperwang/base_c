#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QTimerEvent>
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

    //捕获计时器事件
    virtual void timerEvent(QTimerEvent *event) override;
    // 计时器id
    int id1;
    int id2;

protected:
    // 事件过滤器的使用
    bool eventFilter(QObject *obj, QEvent *ev) override;

private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
