#ifndef STARTWIDGET_H
#define STARTWIDGET_H

#include <QWidget>

namespace Ui {
class StartWidget;
}

class StartWidget : public QWidget
{
    Q_OBJECT

public:
    explicit StartWidget(QWidget *parent = nullptr);
    ~StartWidget();
signals:
    //按钮按下的处理函数中发出的信号
    void button_pressed();
private slots:
    void on_pushButton_clicked();

private:
    Ui::StartWidget *ui;
};

#endif // STARTWIDGET_H
