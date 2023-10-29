#include <QApplication>
#include <QStackedWidget>
#include "containwindow.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    ContainWindow containWindow;
    containWindow.show();
    return a.exec();
}
