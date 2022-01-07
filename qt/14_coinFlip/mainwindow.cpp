#include "mainwindow.h"
#include "ui_mainwindow.h"
#include "mupushbutton.h"
#include <QMediaPlayer>
#include <QUrl>
MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    // 设置主窗口的信息
    // 1. 设置窗口 大小
    setFixedSize(320,588);
    // 2. 设置主窗口图片
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    // 3. 设置主窗口标题
    setWindowTitle("翻转金币");

    //设置退出按钮
    connect(ui->actionquit,&QAction::triggered,[=](){
        this->close();
    });

    // final 加载开始的背景音乐
    QSound *sound = new QSound(":/res/TapButtonSound.wav");
    sound->setParent(this);
    //sound->setLoops(-1);
    QMediaPlayer *bkSound = new QMediaPlayer(this);
    bkSound->setMedia(QUrl("qrc:/res/bkmusic.mp3"));
    bkSound->play();

    // 设置开始按钮
    MuPushButton *startBtn = new MuPushButton(":/res/MenuSceneStartButton.png");
    startBtn->setParent(this);
    // 设置开始按钮位置为中心位置
    startBtn->move(this->width()*0.5 - startBtn->width()*0.5, this->height()*0.7);

    chooseWidget = new ChooseWidget(this);
    // 主窗口监听 chooseWidget的通知事件
    connect(chooseWidget,&ChooseWidget::chooseScenceBack,this,[=](){
        // 优化, 位置衔接正常,不来回跳转
        this->setGeometry(chooseWidget->geometry());

        //接收到chooseWidget返回,则主窗口再次显示
        this->show();
        // chooseWidget窗口隐藏
        chooseWidget->hide();
    });

    // 设置按钮的  单击事件
    connect(startBtn, &QPushButton::clicked,[=](){
        // 开始播放背景音乐
        sound->play();
       qDebug()<< "start btn clicked" ;
       //设置按钮的弹跳效果
       startBtn->zoom1();
       startBtn->zoom2();

       // 单击了开始按钮,把当前windows隐藏,显示chooseWindow
       // 延迟隐藏当前窗口,进入新的窗口
       QTimer::singleShot(500,[=](){
           // 优化, 当前窗口和下个窗口衔接正常,位置不会跳转
          chooseWidget->setGeometry(this->geometry());
          this->hide();
          chooseWidget->show();

       });


    });
}


// 利用PaintEvet 来画背景
void MainWindow::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    // 加载背景图片
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");
    // 画背景图
    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    // 加载小背景图
    pix.load(":/res/Title.png");
    // 图片缩放
    pix = pix.scaled(pix.width()*0.5, pix.height()*0.5);
    painter.drawPixmap(10,30,pix);

}

MainWindow::~MainWindow()
{
    delete ui;
}

