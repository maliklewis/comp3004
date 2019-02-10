#include "staffcontroller.h"
#include <QApplication>


StaffController::StaffController()
{
    databasemanager cuacsdb;
    cuacsdb.dbOpen();
    mainWindow = new MainWindow;
    mainWindow->show();
    this->connect(mainWindow,SIGNAL(staffButtonClicked()),this,SLOT(staffButtonDone()));
}
/*
StaffController::~StaffController()
{
    mainWindow->close();
    delete mainWindow;
    mainWindow = 0;
}
*/


void StaffController::staffButtonDone()
{
    this->mainWindow->hide();
    StaffLogin staffLogin;
    staffLogin.setModal(true);
    staffLogin.exec();

}
