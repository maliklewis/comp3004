#include "mainwindow.h"
#include <QApplication>
#include "staffcontroller.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    StaffController control;
    //scontrol.launch();
    return a.exec();
}
