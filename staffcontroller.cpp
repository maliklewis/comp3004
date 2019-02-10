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
    staffLogin = new StaffLogin;
    this->connect(staffLogin,SIGNAL(loginButtonClicked()),this,SLOT(loginButtonDone()));
    staffLogin->show();
}

void StaffController::loginButtonDone()
{
    QSqlQuery qry;
    qry.prepare("Select * from staff where name = '"+staffLogin->username+"'");
    qDebug()<<"Login Successfull";
    if (qry.exec() && qry.first())
    {
       this->staffLogin->close();
       staffView = new StaffView;
       staffView->show();
       this->connect(staffView,SIGNAL(browseButtonClicked()),this,SLOT(browseButtonDone()));
    }
    else
    {
        qDebug()<<"Login failed";
    }

}

void StaffController::browseButtonDone()
{
    //QSqlQuery qry;
    qDebug()<<"got here";
    this->staffView->hide();
    browseView = new BrowseAnimalsView;
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("Select name, type, breed from animal");
    qry.exec();
    modal->setQuery(qry);
    browseView->getForm()->setModel(modal);
    browseView->show();

}



