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
       this->connect(staffView,SIGNAL(addAnimalButtonClicked()),this,SLOT(addAnimalButtonDone()));

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

void StaffController::addAnimalButtonDone()
{
    this->staffView->hide();
    addAnimalView = new AddAnimalView;
    addAnimalView->show();

    this->connect(addAnimalView,SIGNAL(insertAnimalButtonClicked()),this,SLOT(insertAnimalButtonDone()));
}

void StaffController::insertAnimalButtonDone()
{
    QSqlQuery qry;
    qry.prepare("INSERT INTO animal VALUES (Null,'"+this->addAnimalView->name+"',"
                                                 "'"+this->addAnimalView->type+"',"
                                                 "'"+this->addAnimalView->breed+"',"
                                                 "'"+this->addAnimalView->gender+"',"
                                                 "'"+this->addAnimalView->age+"')");
    qry.exec();
}


