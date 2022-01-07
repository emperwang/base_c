#include "mupushbutton.h"

//MuPushButton::MuPushButton(QWidget *parent) : QPushButton(parent)
//{

//}

MuPushButton::MuPushButton(QString normalImg, QString pressImg)
{
       this->normalImgPath = normalImg;
       this->pressImgPath = pressImg;

       this->setButtonPicture(this->normalImgPath);
}

// 设置按钮背景图片
void MuPushButton::setButtonPicture(QString path)
{
    //加载图片
   QPixmap pix;
   bool ret = pix.load(path);
   if(!ret)
   {
       qDebug() << "Load image error";
       return;
   }

   // 设置本按钮带下为固定
   this->setFixedSize(pix.width(),pix.height());

   // 设置按钮的icon
   this->setIcon(QIcon(pix));

   //设置不规则图片样式
   this->setStyleSheet("QPushButton{border:0px;}");

   // 设置图标大小
   this->setIconSize(QSize(pix.width(),pix.height()));
}

void MuPushButton::zoom1()
{
    // 创建动态对象, this表示那个对象要执行对话, 第二个参数 动画类型
    QPropertyAnimation * animation = new QPropertyAnimation(this,"geometry");
    // 设置动画持续时间
    animation->setDuration(200);
    // 设置起始位置
    animation->setStartValue(QRect(this->x(),this->y()+10,this->width(),this->height()));
    // 设置终点位置
    animation->setEndValue(QRect(this->x(),this->y(),this->width(),this->height()));
    // 设置弹线曲线
    animation->setEasingCurve(QEasingCurve::OutBounce);
    // 执行动画
    animation->start();
}

void MuPushButton::zoom2()
{
    QPropertyAnimation *animation = new QPropertyAnimation(this,"geometry");
    animation->setDuration(300);
    animation->setStartValue(QRect(this->x(),this->y(),this->width(),this->height()));
    animation->setEndValue(QRect(this->x(),this->y()-10,this->width(),this->height()));
    animation->setEasingCurve(QEasingCurve::OutBounce);
    animation->start();
}


// 设置button按下的背景图片
void MuPushButton::mousePressEvent(QMouseEvent *event)
{
    // 如果设置了按下的背景图片,那么说明需要设置按下的背景图片
    if(this->pressImgPath != "")
    {
        this->setButtonPicture(this->pressImgPath);
    }
    // 交由父类进行其他处理
    return QPushButton::mousePressEvent(event);
}

// 设置按钮松开的背景图片
void MuPushButton::mouseReleaseEvent(QMouseEvent *event)
{
    // 同样,如果设置了松开的背景图片,说明需要设置背景图片
    if(this->normalImgPath != "")
    {
        this->setButtonPicture(this->normalImgPath);
    }

    return QPushButton::mouseReleaseEvent(event);
}


















