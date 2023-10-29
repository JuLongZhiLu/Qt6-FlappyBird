#include "containwindow.h"
#include "ui_containwindow.h"
#include "startWidget.h"
#include "mainwindow.h"


ContainWindow::ContainWindow(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ContainWindow)
{
    ui->setupUi(this);

    StartWidget *startWidget=new StartWidget();
    MainWindow *mainWindow=new MainWindow;

    ui->stackedWidget->addWidget(startWidget);
    ui->stackedWidget->addWidget(mainWindow);

    ui->stackedWidget->setCurrentIndex(0);



    connect(startWidget,&StartWidget::button_pressed,[=](){
        ui->stackedWidget->setCurrentIndex(1);
        mainWindow->startGame();
    });
}

ContainWindow::~ContainWindow()
{
    delete ui;
}
