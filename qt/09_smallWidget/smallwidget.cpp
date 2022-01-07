#include "smallwidget.h"
#include "ui_smallwidget.h"

/*
 * 在这里自定义一个组件,可以在主框架中使用
 */
SmallWidget::SmallWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::SmallWidget)
{
    ui->setupUi(this);

    // spanBox值改变,则spider也会跟着移动
    //1. 设置 spanBox函数指针
    void(QSpinBox::*sigFun)(int) = &QSpinBox::valueChanged;
    connect(ui->spinBox, sigFun,ui->horizontalSlider,&QSlider::setValue);

    // 反向关联 slider 和spanBox
    connect(ui->horizontalSlider,&QSlider::valueChanged,ui->spinBox,&QSpinBox::setValue);
}

int SmallWidget::getNum()
{
    return ui->spinBox->value();
}

int SmallWidget::setNum(int value)
{
    ui->spinBox->setValue(value);
    return 0;
}

SmallWidget::~SmallWidget()
{
    delete ui;
}
