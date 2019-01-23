#include "mainwindow.h"
#include <QApplication>
#include "databasemanager.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();
    databasemanager h;
    h.dbOpen();
    return a.exec();
}
