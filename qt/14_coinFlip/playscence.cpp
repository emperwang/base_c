#include "playscence.h"

PLayScence::PLayScence(QWidget *parent) : QMainWindow(parent)
{

}
PLayScence::PLayScence(int level)
{
    this->levelNum = level;
    // 1.设置窗口的基本信息
    // 1.1 设置大小
    setFixedSize(320,588);
    // 1.2 设置icon
    setWindowIcon(QIcon(":/res/Coin0001.png"));
    // 1.3 设置窗口标题
    setWindowTitle("翻金币");

    // 2. 设置menuBar
    QMenuBar *bar = new QMenuBar(this);
    setMenuBar(bar);
    QMenu *menu = bar->addMenu("开始");
    QAction * quit = menu->addAction("退出");
    connect(quit,&QAction::triggered,this,[=](){
        this->close();
    });
    // 15. 设置声音
    // 返回按钮的声音
    QSound *backBtnSound = new QSound(":/res/BackButtonSound.wav");
    // 金币按下的声音
    QSound *coinSound = new QSound(":/res/ConFlipSound.wav");
    // 银币按下的声音

    // 胜利的声音
    QSound *winSound = new QSound(":/res/LevelWinSound.wav");
    //4.显示返回按钮
    MuPushButton * btn = new MuPushButton(":/res/BackButton.png",":/res/BackButtonSelected.png");
    btn->setParent(this);
    btn->move(this->width()-btn->width(),this->height()-btn->height());

    // 6. 监听返回按钮的事件
    connect(btn,&QPushButton::clicked,this,[=](){
        // 返回按钮的声音
        backBtnSound->play();

        qDebug() << "playScence 点击了返回按钮";
        QTimer::singleShot(500,[=](){
            emit this->playScenceBack();
        });
    });

    //5. 显示关卡
    QLabel *label = new QLabel();
    label->setParent(this);
    QFont font;
    font.setFamily("华文新魏");
    font.setPointSize(20);
    label->setFont(font);
    QString disLevel = QString("Level: %1").arg(this->levelNum);
    label->setText(disLevel);
    // 设置大小和位置
    //label->setFixedSize(120,50);
    //label->move(30, this->height()-50);
    label->setGeometry(30,this->height()-50,120,50);

    // 7. 初始化此playScence 关卡对应的游戏数据
    dataConfig config;
    for(int i=0;i<4;i++)
    {
        for(int j=0; j<4;j++)
        {
            gameArray[i][j] = config.mData[this->levelNum][i][j];
        }
    }

    // 13. 设置胜利的 图片
    QString winPicPath = QString(":/res/LevelCompletedDialogBg.png");
    QPixmap pix;
    pix.load(winPicPath);
    QLabel *winLabel = new QLabel();
    winLabel->setPixmap(pix);
    winLabel->setParent(this);
    winLabel->setFixedSize(pix.width(),pix.height());
    // 设置中间位置
    winLabel->move((this->width()-pix.width())*0.5,-pix.height());
    // 同时设置位置和坐标
    //winLabel->setGeometry()

    // 6. 显示金币
    for(int i=0;i<4;i++)
    {
        for(int j=0;j<4;j++)
        {
            //绘制背景图片
            QPixmap pix = QPixmap(":/res/BoardNode(1).png");
            QLabel *label = new QLabel(this);
            label->setGeometry(0,0,pix.width(),pix.height());
            label->setPixmap(pix);
            label->setParent(this);
            label->move(57+i*50,200+j*50);

            QString str;
            // 8. 根据游戏数据设置 到底是显示金币 还是显示银币
            if(this->gameArray[i][j] == 0)
            {
                str = QString(":/res/Coin0008.png");
            }else{
                str = QString(":/res/Coin0001.png");
            }

            // 7.显示金币
            MuCoin *coin = new MuCoin(str);
            coin->setParent(this);
            coin->move(59+i*50,202+j*50);

            // 10. 记录起每个金币的指针信息,用于后面周围金币翻转使用
            coins[i][j] = coin;

            // 8. 记录金币的信息,用于翻转使用
            coin->flag = this->gameArray[i][j];
            coin->posX = i;
            coin->posY = j;

            // 9.监听coin的单击事件
            connect(coin,&QPushButton::clicked,[=](){
                // 翻金币的声音
                coinSound->play();
                //在开始此金币翻转前,先禁止其他金币被翻转
                for(int i=0;i<4;i++)
                {
                    for(int j=0;j<4;j++)
                    {
                        coins[i][j]->isWin=true;
                    }
                }


                coin->changeFlag();

                // 11. 延迟翻转周围的金币
                QTimer::singleShot(200,[=](){
                    // 周围金币的右边
                    if((coin->posX + 1) <= 3)
                    {
                        coins[coin->posX+1][coin->posY]->changeFlag();
                        gameArray[coin->posX+1][coin->posY] = gameArray[coin->posX+1][coin->posY]==0?1:0;
                    }

                    // 周围金币的左边
                    if((coin->posX-1) >= 0)
                    {
                        coins[coin->posX-1][coin->posY]->changeFlag();
                        gameArray[coin->posX-1][coin->posY] = gameArray[coin->posX-1][coin->posY]==0?1:0;
                    }
                    // 周围金币上的上面
                    if((coin->posY+1) <= 3)
                    {
                        coins[coin->posX][coin->posY+1]->changeFlag();
                        gameArray[coin->posX][coin->posY+1] = gameArray[coin->posX][coin->posY+1]==0?1:0;
                    }

                    // 周围金币的下面
                    if((coin->posY-1) >= 0)
                    {
                        coins[coin->posX][coin->posY-1]->changeFlag();
                        gameArray[coin->posX][coin->posY-1] = gameArray[coin->posX][coin->posY-1]==0?1:0;
                    }

                    //此金币翻转完后,再允许其他金币被翻转
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            coins[i][j]->isWin=false;
                        }
                    }

                    // 12. 判断是否胜利
                    this->isWin = true;

                    // 判断是否还有反面的金币,如果有,则没有胜利
                    for(int i=0;i<4;i++)
                    {
                        for(int j=0;j<4;j++)
                        {
                            if(coins[i][j]->flag == false)
                            {
                                this->isWin = false;
                                break;
                            }
                        }
                    }

                    // 如果isWin==true, 则表示胜利了
                    if(isWin)
                    {
                        qDebug() << "胜利....";
                        // 给所有金币设置胜利标识
                        for(int i=0;i<4;i++)
                        {
                            for(int j=0;j<4;j++)
                            {
                                coins[i][j]->isWin = true;
                            }
                        }
                        // 14. 设置胜利时 图片的动画
                        QPropertyAnimation *animation = new QPropertyAnimation(winLabel,"geometry");
                        //设置开始位置
                        animation->setStartValue(QRect(winLabel->x(),winLabel->y(),winLabel->width(),winLabel->height()));
                        // 设置结果位置
                        animation->setEndValue(QRect(winLabel->x(),winLabel->y()+114,winLabel->width(),winLabel->height()));
                        // 设置持续时间
                        animation->setDuration(1000);
                        // 设置动画的 效果
                        animation->setEasingCurve(QEasingCurve::OutBounce);
                        // 开始动画
                        animation->start();

                        // 胜利的声音
                        winSound->play();
                    }


                });
            });
        }
    }
}

// 3. 背景设置
void PLayScence::paintEvent(QPaintEvent *event)
{
    QPainter painter(this);
    QPixmap pix;
    pix.load(":/res/PlayLevelSceneBg.png");

    painter.drawPixmap(0,0,this->width(),this->height(),pix);

    pix.load(":/res/Title.png");
    pix = pix.scaled(pix.width()*0.5,pix.height()*0.5);
    painter.drawPixmap(10,30,pix.width(),pix.height(),pix);
}
