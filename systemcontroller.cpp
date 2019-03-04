#include "systemcontroller.h"

SystemController::SystemController()
{
    databasemanager cuacsdb;
    cuacsdb.dbOpen();
    mainWindow = new MainWindow;
    //staffLogin = new StaffLogin;
    mainWindow->show();
    qDebug()<<"started here";
    this->connect(mainWindow,SIGNAL(staffButtonClicked()),this,SLOT(staffButtonDone()));
    this->connect(mainWindow,SIGNAL(clientButtonClicked()),this,SLOT(clientButtonDone()));
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
    staffLogin->show();
}

void SystemController::clientButtonDone()
{
    qDebug()<<"Main Window: CLIENT button pressed";
    this->mainWindow->hide();
    clientLogin = new ClientLogin;
    this->connect(clientLogin,SIGNAL(clientLoginButtonClicked()),this,SLOT(clientLoginButtonDone()));
    clientLogin->show();
}

void SystemController::staffLoginButtonDone()
{
    qDebug()<<"Staff Login Window: LOGIN button pressed";
    QSqlQuery qry;
    qry.prepare("Select * from staff where name = '"+staffLogin->username+"'");
    if (qry.exec() && qry.first())
    {
       qDebug()<<"Staff login Successfull";
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
    qry.prepare("Select * from client where name = '"+clientLogin->username+"'");
    if (qry.exec() && qry.first())
    {
       qDebug()<<"Client login Successfull";
       this->clientLogin->hide();
       clientControl = new ClientController;
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
