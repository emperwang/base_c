#ifndef SMALLWIDGET_H
#define SMALLWIDGET_H

#include <QWidget>
#include <QSpinBox>

namespace Ui {
class SmallWidget;
}

class SmallWidget : public QWidget
{
    Q_OBJECT

public:
    explicit SmallWidget(QWidget *parent = nullptr);

    int getNum();
    int setNum(int value);
    ~SmallWidget();

private:
    Ui::SmallWidget *ui;
};

#endif // SMALLWIDGET_H
