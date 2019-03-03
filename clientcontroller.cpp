#include "clientcontroller.h"
#include <QApplication>

ClientController::ClientController()
{
    databasemanager cuacsdb;
    cuacsdb.dbOpen();
    //mainWindow = new MainWindow;
    //this->connect(staffController->mainWindow,SIGNAL(clientButtonClicked()),this,SLOT(clientButtonDone()));
}

ClientController::~ClientController()
{
    qDebug()<<"destructor";
}

void ClientController::clientButtonDone()
{
    //User chooses to login as a staff member
    qDebug()<<"Main Window: CLIENT button pressed";
    //staffController->mainWindow->hide();
    //clientLogin = new ClientLogin;
    //this->connect(staffLogin,SIGNAL(loginButtonClicked()),this,SLOT(loginButtonDone()));
    //clientLogin->show();
}
