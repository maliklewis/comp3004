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
    qDebug()<<"Main Window: STAFF button pressed";
    this->mainWindow->hide();
    staffLogin = new StaffLogin;
    this->connect(staffLogin,SIGNAL(loginButtonClicked()),this,SLOT(loginButtonDone()));
    staffLogin->show();
}

void StaffController::loginButtonDone()
{
    qDebug()<<"Staff Login Window: LOGIN button pressed";
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
    qDebug()<<"Main Staff Window: Browse Animals button pressed";
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
    this->connect(browseView,SIGNAL(tableItemClicked()),this,SLOT(tableItemDone()));


}

void StaffController::browseBackButtonDone()
{
    qDebug()<<"Animal List Window: Back button pressed";
    //return to staff view from browsing animals
    this->browseView->hide();
    this->staffView->show();
}

void StaffController::staffLogoutDone()
{
    //staff member logouts of the system
    this->staffView->close();


    this->mainWindow->show();
}

void StaffController::addAnimalButtonDone()
{
    qDebug()<<"Main Staff Window: Add Animal button pressed";
    //user chooses to add an animal
    this->staffView->hide();
    addAnimalView = new AddAnimalView;
    addAnimalView->show();

    this->connect(addAnimalView,SIGNAL(insertAnimalButtonClicked()),this,SLOT(insertAnimalButtonDone()));
    this->connect(addAnimalView,SIGNAL(insertAnimalBackButtonClicked()),this,SLOT(insertAnimalBackButtonDone()));

}


void StaffController::insertAnimalButtonDone()
{
    qDebug()<<"Add Animal Window: Add button pressed";
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
    qDebug()<<"Add Animal Window: Back button pressed";
    //return to staff view from add animal form
    this->addAnimalView->hide();
    this->staffView->show();
}

void StaffController::tableItemDone()
{
    //browseView->tableRow;
    animalDetailsView = new AnimalDetailsView;
    QSqlQuery qry;

    qry.prepare("SELECT name,type,breed,gender,age from animal WHERE animal_id = '"+browseView->tableRowString+"'");
    qry.exec();
    //QSqlRecord rec = qry.record();
    //int nameval = rec.indexOf("name");
    qry.next();
    //qDebug()<<nameval;
    //qDebug()<<qry.value(nameval).toString();
    animalDetailsView->getName()->setText(qry.value(0).toString());
    animalDetailsView->getType()->setText(qry.value(1).toString());
    animalDetailsView->getBreed()->setText(qry.value(2).toString());
    animalDetailsView->getGender()->setText(qry.value(3).toString());
    animalDetailsView->getAge()->setText(qry.value(4).toString() + " years");
    animalDetailsView->show();
}
