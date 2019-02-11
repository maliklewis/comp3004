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

StaffController::~StaffController()
{
    mainWindow->close();
    staffView->close();
    browseView->close();
    addAnimalView->close();
    delete staffView;
    delete mainWindow;
    delete browseView;
    delete addAnimalView;
    mainWindow = 0;
    staffView = 0;
    browseView = 0;
    addAnimalView = 0;
    qDebug()<<"destructor";
}



void StaffController::staffButtonDone()
{
    //User chooses to login as a staff member
    this->mainWindow->hide();
    staffLogin = new StaffLogin;
    this->connect(staffLogin,SIGNAL(loginButtonClicked()),this,SLOT(loginButtonDone()));
    staffLogin->show();
}

void StaffController::loginButtonDone()
{
    QSqlQuery qry;
    qry.prepare("Select * from staff where name = '"+staffLogin->username+"'");

    //If the current login succeeds
    if (qry.exec() && qry.first())
    {
       qDebug()<<"Login Successfull";
       this->staffLogin->close();
       staffView = new StaffView;
       staffView->show();
       this->connect(staffView,SIGNAL(browseButtonClicked()),this,SLOT(browseButtonDone()));
       this->connect(staffView,SIGNAL(addAnimalButtonClicked()),this,SLOT(addAnimalButtonDone()));
       this->connect(staffView,SIGNAL(staffLogoutClicked()),this,SLOT(staffLogoutDone()));

    }
    else
    {
        qDebug()<<"Login failed";
        QMessageBox::information(staffLogin,tr("Error"),tr("Login Failed"));
        staffLogin->getForm()->clear();
    }

}

void StaffController::browseButtonDone()
{
    //user chooses to browse animals
    this->staffView->hide();
    browseView = new BrowseAnimalsView;
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("Select name, type, breed from animal");
    qry.exec();
    modal->setQuery(qry);
    browseView->getForm()->setModel(modal);
    browseView->show();

    this->connect(browseView,SIGNAL(browseBackButtonClicked()),this,SLOT(browseBackButtonDone()));


}

void StaffController::browseBackButtonDone()
{
    //return to staff view from browsing animals
    this->browseView->hide();
    this->staffView->show();
}

void StaffController::staffLogoutDone()
{
    //staff member logouts of the system
    this->staffView->close();
    this->browseView->close();
    this->addAnimalView->close();
    this->mainWindow->show();
}

void StaffController::addAnimalButtonDone()
{
    //user chooses to add an animal
    this->staffView->hide();
    addAnimalView = new AddAnimalView;
    addAnimalView->show();

    this->connect(addAnimalView,SIGNAL(insertAnimalButtonClicked()),this,SLOT(insertAnimalButtonDone()));
    this->connect(addAnimalView,SIGNAL(insertAnimalBackButtonClicked()),this,SLOT(insertAnimalBackButtonDone()));

}


void StaffController::insertAnimalButtonDone()
{
    //user attempts to add an animal to the database
    bool ret = false;

    QSqlQuery qry;
    if (this->addAnimalView->name != "" && this->addAnimalView->age != ""){
        qry.prepare("INSERT INTO animal VALUES (Null,'"+this->addAnimalView->name+"',"
                                                     "'"+this->addAnimalView->type+"',"
                                                     "'"+this->addAnimalView->breed+"',"
                                                     "'"+this->addAnimalView->gender+"',"
                                                     "'"+this->addAnimalView->age+"')");
        ret = qry.exec();
    }


    if (ret){
        QMessageBox::information(addAnimalView,tr("Success!"),tr("Animal Added"));
    }
    else{
        QMessageBox::information(addAnimalView,tr("Error!"),tr("Missing Field"));
    }
}

void StaffController::insertAnimalBackButtonDone()
{
    //return to staff view from add animal form
    this->addAnimalView->hide();
    this->staffView->show();
}
