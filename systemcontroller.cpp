#include "systemcontroller.h"

SystemController::SystemController()
{
    databasemanager* cuacsdb = databasemanager::getInstance();
    cuacsdb->dbOpen();
    mainWindow = new MainWindow;
    mainWindow->show();
    qDebug()<<"started here";
    this->connect(mainWindow,SIGNAL(staffButtonClicked()),this,SLOT(staffButtonDone()));
    this->connect(mainWindow,SIGNAL(clientButtonClicked()),this,SLOT(clientButtonDone()));
}

SystemController* SystemController::instance = 0;

SystemController* SystemController::getInstance()
{
    if (instance == 0)
    {
        instance = new SystemController();
    }
    return instance;
}

SystemController::~SystemController()
{
    qDebug()<<"destructor";
}

void SystemController::staffButtonDone()
{
    //User chooses to login as a staff member
    qDebug()<<"Main Window: STAFF button pressed";
    this->mainWindow->hide();
    staffLogin = new StaffLogin;
    this->connect(staffLogin,SIGNAL(loginButtonClicked()),this,SLOT(staffLoginButtonDone()));
    this->connect(staffLogin,SIGNAL(staffLoginBackButtonClicked()),this,SLOT(staffLoginBackButtonDone()));
    staffLogin->show();
}

void SystemController::clientButtonDone()
{
    qDebug()<<"Main Window: CLIENT button pressed";
    this->mainWindow->hide();
    clientLogin = new ClientLogin;
    this->connect(clientLogin,SIGNAL(clientLoginButtonClicked()),this,SLOT(clientLoginButtonDone()));
    this->connect(clientLogin,SIGNAL(clientLoginBackButtonClicked()),this,SLOT(clientLoginBackButtonDone()));
    clientLogin->show();
}

void SystemController::staffLoginButtonDone()
{
    qDebug()<<"Staff Login Window: LOGIN button pressed";
    QSqlQuery qry;
    qry.prepare("Select * from staff where email = '"+staffLogin->username+"'");
    if (qry.exec() && qry.first())
    {
       qDebug()<<"Staff login Successfull" << qry.value(1);
       this->staffLogin->hide();
       staffControl = new StaffController;
       this->connect(staffControl,SIGNAL(showMain()),this,SLOT(loggedOutDone()));
    }
    else
    {
        qDebug()<<"Login failed";
        QMessageBox::information(staffLogin,tr("Error"),tr("Login Failed"));
        this->staffLogin->getForm()->clear();
    }

}

void SystemController::clientLoginButtonDone()
{
    qDebug()<<"Client Login Window: LOGIN button pressed";
    QSqlQuery qry;
    qry.prepare("Select * from client where email = '"+clientLogin->username+"'");
    if (qry.exec() && qry.first())
    {
       qDebug()<<"Client login Successfull" << qry.value(1);
       this->clientLogin->hide();
       clientControl = new ClientController;
       clientControl->username =qry.value(1).toString();
       this->connect(clientControl,SIGNAL(showMain()),this,SLOT(loggedOutDone()));
    }
    else
    {
        qDebug()<<"Login failed";
        QMessageBox::information(clientLogin,tr("Error"),tr("Login Failed"));
        //this->clientLogin->getForm()->clear();
    }

}

void SystemController::loggedOutDone()
{
    qDebug()<<"system logout function";
    this->mainWindow->show();
}

void SystemController::staffLoginBackButtonDone()
{
    qDebug()<<"STAFF login window: Back button pressed";
    this->staffLogin->hide();
    this->mainWindow->show();
}

void SystemController::clientLoginBackButtonDone()
{
    qDebug()<<"STAFF login window: Back button pressed";
    this->clientLogin->hide();
    this->mainWindow->show();
}
