#include "startwidget.h"
#include "ui_startwidget.h"

StartWidget::StartWidget(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::StartWidget)
{
    ui->setupUi(this);
//    setStyleSheet("background-color: green;");

}

StartWidget::~StartWidget()
{
    delete ui;
}

void StartWidget::on_pushButton_clicked()
{
    emit button_pressed();
}

