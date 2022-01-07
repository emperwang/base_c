#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QPainter>
#include <QSound>
#include "choosewidget.h"

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

protected:

    virtual void paintEvent(QPaintEvent *event);


private:
    Ui::MainWindow *ui;
    ChooseWidget *chooseWidget = nullptr;
};
#endif // MAINWINDOW_H
