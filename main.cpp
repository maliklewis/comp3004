#include "mainwindow.h"
#include <QApplication>
#include "systemcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    SystemController control;
    return a.exec();
}
