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
       this->connect(staffView,SIGNAL(addClientButtonClicked()),this,SLOT(addClientButtonDone()));
       this->connect(staffView,SIGNAL(browseClientsButtonClicked()),this,SLOT(browseClientsButtonDone()));
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

void StaffController::browseClientsButtonDone()
{
    qDebug()<<"Main Staff Window: Browse Clients button pressed";

    //user chooses to browse clients
    this->staffView->hide();
    browseClientsView = new BrowseClientView;
    QSqlQueryModel *modal = new QSqlQueryModel();
    QSqlQuery qry;
    qry.prepare("Select name, number, email from client");
    qry.exec();
    modal->setQuery(qry);
    browseClientsView->getForm()->setModel(modal);
    browseClientsView->show();

    this->connect(browseClientsView,SIGNAL(tableItemClicked()),this,SLOT(clientTableItemDone()));
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
        QMessageBox::information(addAnimalView,tr("Error!"),tr("Missing Field(s)"));
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
    qry.next();
    animalDetailsView->getName()->setText(qry.value(0).toString());
    animalDetailsView->getType()->setText(qry.value(1).toString());
    animalDetailsView->getBreed()->setText(qry.value(2).toString());
    animalDetailsView->getGender()->setText(qry.value(3).toString());
    animalDetailsView->getAge()->setText(qry.value(4).toString() + " years");
    animalDetailsView->show();
}

void StaffController::clientTableItemDone()
{
    //test
}

void StaffController::addClientButtonDone()
{
    qDebug()<<"Main Staff Window: Add Client button pressed";
    this->staffView->hide();
    addClientView = new addclientview;
    addClientView->show();

    this->connect(addClientView,SIGNAL(insertClientButtonClicked()),this,SLOT(insertClientButtonDone()));
    this->connect(addClientView,SIGNAL(insertClientBackButtonClicked()),this,SLOT(insertClientBackButtonDone()));
}

void StaffController::insertClientButtonDone()
{
    qDebug()<<"Add Client Window: Add button pressed";

    //user attempts to add an animal to the database
    bool ret = false;

    QSqlQuery qry;
    if (this->addClientView->name != "" && this->addClientView->number != "" && this->addClientView->email != ""){
        qry.prepare("INSERT INTO client VALUES (Null,'"+this->addClientView->name+"',"
                                                     "'"+this->addClientView->number+"',"
                                                     "'"+this->addClientView->email+"')");
        ret = qry.exec();
    }


    if (ret){
        QMessageBox::information(addClientView,tr("Success!"),tr("Client Added"));
    }
    else{
        QMessageBox::information(addClientView,tr("Error!"),tr("Missing Field(s)"));
    }
}

void StaffController::insertClientBackButtonDone()
{
    qDebug()<<"Add Client Window: Back button pressed";

    //return to staff view from add client form
    this->addClientView->hide();
    this->staffView->show();
}
