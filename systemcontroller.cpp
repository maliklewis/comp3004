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

void SystemController::staffLoginButtonDone()
{
    qDebug()<<"Staff Login Window: LOGIN button pressed";
    QSqlQuery qry;
    qry.prepare("Select * from staff where name = '"+staffLogin->username+"'");
    if (qry.exec() && qry.first())
    {
       qDebug()<<"Login Successfull";
       this->staffLogin->close();
       staffControl = new StaffController;
    }
    else
    {
        qDebug()<<"Login failed";
        QMessageBox::information(staffLogin,tr("Error"),tr("Login Failed"));
        staffLogin->getForm()->clear();
    }
    //staf = new StaffView;
    this->connect(staffControl,SIGNAL(showMain()),this,SLOT(loggedOutDone()));
}

void SystemController::loggedOutDone()
{
    qDebug()<<"system logout function";
    this->mainWindow->show();
}
