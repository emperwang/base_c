#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QBitmap>
#include <QPainter>
#include <QPicture>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();

    void usePicture();
    virtual void paintEvent(QPaintEvent *event);


private:
    Ui::MainWindow *ui;
};
#endif // MAINWINDOW_H
