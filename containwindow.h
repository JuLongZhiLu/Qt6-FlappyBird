#ifndef CONTAINWINDOW_H
#define CONTAINWINDOW_H

#include <QWidget>
#include <QStackedWidget>

namespace Ui {
class ContainWindow;
}

class ContainWindow : public QWidget
{
    Q_OBJECT

public:
    explicit ContainWindow(QWidget *parent = nullptr);
    ~ContainWindow();

private:
    Ui::ContainWindow *ui;
};

#endif // CONTAINWINDOW_H
