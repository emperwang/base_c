#include "choosewidget.h"

ChooseWidget::ChooseWidget(QWidget *parent) : QMainWindow(parent)
{
    //对chooseWidget的设置
    //1. 设置大小
    setFixedSize(320,588);

    //2.设置窗口 icon
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    //3. 设置标题
    setWindowTitle("选择关卡");

    // 5. 设置menu
    QMenuBar *menuBar = new QMenuBar(this);
    this->setMenuBar(menuBar);
    QMenu *startMenu = menuBar->addMenu("开始");
    QAction *actionExit = startMenu->addAction("退出");

    // 5.1 设置退出按钮的退出功能
    connect(actionExit,&QAction::triggered,[=](){
        this->close();
    });


    // 8. 设置按钮的声音
    QSound *backBtnSound = new QSound(":/res/BackButtonSound.wav");
    QSound *selectBtnSound = new QSound(":/res/TapButtonSound.wav");

    // 6. 设置右下角的返回按钮
    MuPushButton* btnBack = new MuPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    btnBack->setParent(this);
    btnBack->move(this->width()-btnBack->width(),this->height()-btnBack->height());

    connect(btnBack,&QPushButton::clicked,[=](){
        // 设置返回按钮的声音
        backBtnSound->play();

       qDebug() << "back btn click" ;
       // 按下了返回按钮,则通知主窗口; 也就是给主窗口发送一个信号
       QTimer::singleShot(500,[=](){
          emit  chooseScenceBack(); // 发送信号
       });
    });

    // 7. 初始化关卡选择按钮
    for(int i=0; i<20;i++)
    {
        MuPushButton *btn = new MuPushButton(":/res/LevelIcon.png");
        btn->setParent(this);
        btn->move(20+i%4*70,130+i/4*70);

        // 监听每一个按钮的单击事件,用于选择关卡
        connect(btn,&QPushButton::clicked,[=](){
            // 选择关卡的生硬
            selectBtnSound->play();
           QString str = QString("选择的关卡是:%1").arg(i+1);
           qDebug()<<str;

            this->hide();
           // 8.在这里创建playScence 进行游戏的创建
           scence = new PLayScence(i+1);
           // 优化scence 和chooseWidget 窗口位置衔接
           scence->setGeometry(this->geometry());
           scence->show();

           // 监听scence的信号
           connect(scence,&PLayScence::playScenceBack,[=](){
               // 优化: 位置衔接
               this->setGeometry(scence->geometry());
               scence->hide();
                this->show();
               delete scence;
                scence = nullptr;
           });
        });
        // 为按钮设置显示的关卡
        QLabel *label = new QLabel(this);
        // 设置label的大小
        label->setFixedSize(btn->width(),btn->height());
        // 设置label的位置
        label->move(20+i%4*70,130+i/4*70);
        // 设置label的显示 格式
        label->setAlignment(Qt::AlignHCenter | Qt::AlignVCenter);
        label->setText(QString::number(i+1));
        // 设置label的 鼠标穿透属性,用于让 btn接收到鼠标单击事件
        label->setAttribute(Qt::WA_TransparentForMouseEvents);
    }
}

// 4.设置背景图片
void ChooseWidget::paintEvent(QPaintEvent *event)
{
    // 4.1 设置画笔
    QPainter painer(this);
    QPixmap pix;
    // 4.2 加载图片
    pix.load(":/res/OtherSceneBg.png");
    // 4.3 画背景图片
    painer.drawPixmap(0,0,this->width(),this->height(),pix);

    // 4.4 加载title
    pix.load(":/res/Title.png");
    painer.drawPixmap((this->width()-pix.width())*0.5,20,pix.width(),pix.height(),pix);
}
