#include "mainwindow.h"
#include "./ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);


}


void MainWindow::startGame(){
    // 创建小鸟标签
   birdLabel = new QLabel("Bird", this);
   birdLabel->setFixedSize(50, 50);//设置标签的固定大小为50,50
   birdLabel->move(100, 200);
   birdLabel->show();

   // 创建定时器，用于生成管道和移动管道
   pipeGenerateTimer = new QTimer(this);
   pipeMoveTimer = new QTimer(this);
   connect(pipeGenerateTimer, &QTimer::timeout, this, &MainWindow::generatePipe);
   connect(pipeMoveTimer, &QTimer::timeout, this, &MainWindow::movePipes);

   // 启动定时器
   pipeGenerateTimer->start(5000);
    pipeMoveTimer->start(50);
   // 启动小鸟的移动
   birdMoveTimer = new QTimer(this);
   connect(birdMoveTimer, &QTimer::timeout, this, &MainWindow::moveBird);
   birdMoveTimer->start(50); // 每隔50毫秒移动小鸟
}


void MainWindow::keyPressEvent(QKeyEvent *event)
   {
       // 响应空格键，控制小鸟向上飞
       if (event->key() == Qt::Key_Space)
       {
           birdY -= 30; // 向上移动30像素
           birdLabel->move(birdX, birdY);
       }
   }

void MainWindow::generatePipe(){
    // 随机生成管道高度
    int pipeHeight = QRandomGenerator::global()->bounded(100, 300);//生成100到300之间的随机数，不包括300

    // 创建上方管道标签
    QLabel *pipeTopLabel = new QLabel(this);
    pipeTopLabel->setFixedSize(50, pipeHeight);//设置管道的固定宽带为50，高度为pipeHeight
    pipeTopLabel->move(width(), 0); // 初始位置在窗口右侧顶部
    pipeTopLabel->setStyleSheet("background-color: green;");
    pipeTopLabel->show();

    // 创建下方管道标签
    QLabel *pipeBottomLabel = new QLabel(this);
    pipeBottomLabel->setFixedSize(50, height() - pipeHeight - gapSize);
    pipeBottomLabel->move(width(), pipeHeight + gapSize); // 初始位置在窗口右侧下方
    pipeBottomLabel->setStyleSheet("background-color: green;");
    pipeBottomLabel->show();

    pipes.append(qMakePair(pipeTopLabel, pipeBottomLabel));
}

void MainWindow::movePipes(){
    for (auto &pipePair : pipes)
   {
       QLabel *pipeTopLabel = pipePair.first;
       QLabel *pipeBottomLabel = pipePair.second;

       // 向左移动管道
       pipeTopLabel->move(pipeTopLabel->x() - pipeSpeed, pipeTopLabel->y());
       pipeBottomLabel->move(pipeBottomLabel->x() - pipeSpeed, pipeBottomLabel->y());

       // 判断是否碰撞到小鸟
       if (pipeTopLabel->geometry().intersects(birdLabel->geometry()) ||
           pipeBottomLabel->geometry().intersects(birdLabel->geometry()))
       {
           // 碰撞处理逻辑
           qDebug("Collision!");
           pipeGenerateTimer->stop();
           pipeMoveTimer->stop();
           birdMoveTimer->stop();
           QMessageBox::information(nullptr, "消息", "游戏结束");

       }

       // 如果管道移出窗口，删除管道标签
       if (pipeTopLabel->x() + pipeTopLabel->width() < 0)
       {
           delete pipeTopLabel;
           delete pipeBottomLabel;
           pipes.removeOne(pipePair);
       }
    }
}

void MainWindow::moveBird(){
    // 向下移动小鸟
    birdY += birdSpeed;
    birdLabel->move(birdX, birdY);

    // 碰撞检测
    if (birdLabel->y() + birdLabel->height() > height())
    {
      // 掉落到窗口底部，游戏结束
        qDebug("Game Over!");
        pipeGenerateTimer->stop();
        pipeMoveTimer->stop();
        birdMoveTimer->stop();
        QMessageBox::information(nullptr, "消息", "游戏结束");
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}



