#include "mainwindow.h"
#include <QAction>
#include <QLabel>
#include <QStatusBar>
#include <QDockWidget>
#include <QTextEdit>

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
{
    // 重新设置大小
    this->resize(600,400);
    //添加menuBar
    QMenuBar *qmenuBar = menuBar();
    setMenuBar(qmenuBar);

    //为menuBar添加选项
    QMenu *newqmenu = new QMenu(this);
    newqmenu->setTitle("新建");

    qmenuBar->addMenu(newqmenu);
    QAction *openAction = new QAction("打开",this);
    newqmenu->addAction(openAction);

    // 添加分割线
    newqmenu->addSeparator();
    QAction *saveAction = new QAction("保存",this);
    newqmenu->addAction(saveAction);

    QMenu *editMenu = new QMenu(this);
    editMenu->setTitle("编辑");
    qmenuBar->addMenu(editMenu);
    // 添加toolbar
    QToolBar *qToolbar = new QToolBar(this);
    //addToolBar(qToolbar);

    // 设置toolbar的默认位置
    // 添加toolbar 并设置默认的显示位置
    addToolBar(Qt::LeftToolBarArea,qToolbar);
    qToolbar->addAction(openAction);
    qToolbar->addSeparator();
    qToolbar->addAction(saveAction);


    // 设置toolbar的可显示位置
    qToolbar->setAllowedAreas(Qt::LeftToolBarArea|Qt::RightToolBarArea);
    qToolbar->setFloatable(false);


    // 设置状态栏
    QStatusBar *qStatusBar = new QStatusBar(this);
    setStatusBar(qStatusBar);
    QLabel *label = new QLabel("提示信息", this);
    qStatusBar->addWidget(label);

    QLabel *label2 = new QLabel("提示信息2", this);
    qStatusBar->addPermanentWidget(label2);

    // 设置铆接部件  dock
     QDockWidget *qDockWidget = new QDockWidget("部件",this);
     addDockWidget(Qt::BottomDockWidgetArea,qDockWidget);

    // 设置中心区域
    QTextEdit *edit = new QTextEdit("中心", this);
    setCentralWidget(edit);
}

MainWindow::~MainWindow()
{
}

