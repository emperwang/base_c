#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QLibrary>

QT_BEGIN_NAMESPACE
namespace Ui { class Widget; }
QT_END_NAMESPACE


class __declspec(dllimport) CMath
{
public:
    CMath();
    virtual ~CMath();

    int sub(int, int);

    static double PI;
};

class Widget : public QWidget
{
    Q_OBJECT

public:
    Widget(QWidget *parent = nullptr);
    ~Widget();

private:
    Ui::Widget *ui;
};
#endif // WIDGET_H
