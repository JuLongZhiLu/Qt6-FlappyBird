#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QMainWindow>
#include <QLabel>
#include <QTimer>
#include <QRandomGenerator>
#include <QKeyEvent>
#include <QMessageBox>

QT_BEGIN_NAMESPACE
namespace Ui { class MainWindow; }
QT_END_NAMESPACE

class MainWindow : public QMainWindow
{
    Q_OBJECT

public:
    MainWindow(QWidget *parent = nullptr);
    ~MainWindow();
    void startGame();

protected:
    void keyPressEvent(QKeyEvent *event) override;

private:
    Ui::MainWindow *ui;

    QLabel *birdLabel;
    QTimer *pipeGenerateTimer;
    QTimer *pipeMoveTimer;
    QTimer *birdMoveTimer;
    QList<QPair<QLabel*, QLabel*>> pipes;
    int birdX = 100; // 小鸟的初始位置
    int birdY = 200;
    int birdSpeed = 5; // 小鸟的下落速度
    int pipeSpeed = 5; // 管道的移动速度
    int gapSize = 100; // 管道之间的间隔

    void generatePipe();
    void movePipes();
    void moveBird();
};
#endif // MAINWINDOW_H
