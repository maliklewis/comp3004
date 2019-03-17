#include "staffcontroller.h"
#include <QApplication>


StaffController::StaffController()
{
    loginButtonDone();
}

StaffController::~StaffController()
{

    qDebug()<<"destructor";
}

void StaffController::loginButtonDone()
{
    staffView = new StaffView;
    staffView->show();
    this->connect(staffView,SIGNAL(browseButtonClicked()),this,SLOT(browseButtonDone()));
    this->connect(staffView,SIGNAL(addAnimalButtonClicked()),this,SLOT(addAnimalButtonDone()));
    this->connect(staffView,SIGNAL(staffLogoutClicked()),this,SLOT(staffLogoutDone()));
    this->connect(staffView,SIGNAL(addClientButtonClicked()),this,SLOT(addClientButtonDone()));
    this->connect(staffView,SIGNAL(browseClientsButtonClicked()),this,SLOT(browseClientsButtonDone()));
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

    this->connect(browseClientsView,SIGNAL(browseClientsBackButtonClicked()),this,SLOT(browseClientsBackButtonDone()));
    this->connect(browseClientsView,SIGNAL(clientTableItemClicked()),this,SLOT(clientTableItemDone()));
}

void StaffController::staffLogoutDone()
{
    qDebug()<<"Staff has logged out";

    //staff member logouts of the system
    emit showMain();
    this->staffView->close();
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
                                                     "'"+this->addAnimalView->age+"',"
                                                     "'"+this->addAnimalView->housetrained+"',"
                                                     "'"+this->addAnimalView->specialneeds+"',"
                                                     "'"+this->addAnimalView->lifespan+"',"
                                                     "'"+this->addAnimalView->size+"',"
                                                     "'"+this->addAnimalView->carecost+"',"
                                                     "'"+this->addAnimalView->shedAmount+"',"
                                                     "'"+this->addAnimalView->aggression+"',"
                                                     "'"+this->addAnimalView->playfulness+"',"
                                                     "'"+this->addAnimalView->solitudialBehavior+"',"
                                                     "'"+this->addAnimalView->diseaseResistance+"',"
                                                     "'"+this->addAnimalView->parasiticResistance+"',"
                                                     "'"+this->addAnimalView->goodForNowners+"',"
                                                     "'"+this->addAnimalView->trainingEase+"',"
                                                     "'"+this->addAnimalView->environmentType+"',"
                                                     "'"+this->addAnimalView->winged+"',"
                                                     "'"+this->addAnimalView->vocal+"',"
                                                     "'"+this->addAnimalView->clawState+"')");
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

    qry.prepare("SELECT name,type,breed,gender,age,houstrained,specialNeeds,lifeSpan,size,playfulness,winged,costOfCare,sheddingAmount,"
                "aggression,solitudialBehaviour,diseaseResistance,parasiticResistance,goodforNOwners,"
                "easeOfTraining,environmentType,vocal,clawState from animal WHERE animal_id = '"+browseView->tableRowString+"'");
    qry.exec();
    qry.next();
    animalDetailsView->getName()->setText(qry.value(0).toString());
    animalDetailsView->getName()->setReadOnly(true);
    animalDetailsView->getType()->setText(qry.value(1).toString());
    animalDetailsView->getType()->setReadOnly(true);
    animalDetailsView->getBreed()->setText(qry.value(2).toString());
    animalDetailsView->getBreed()->setReadOnly(true);
    animalDetailsView->getGender()->setText(qry.value(3).toString());
    animalDetailsView->getGender()->setReadOnly(true);
    animalDetailsView->getAge()->setText(qry.value(4).toString() + " years");
    animalDetailsView->getAge()->setReadOnly(true);
    animalDetailsView->getHousetrained()->setText(qry.value(5).toString());
    animalDetailsView->getSpecial()->setText(qry.value(6).toString());
    animalDetailsView->getSpan()->setText(qry.value(7).toString());
    animalDetailsView->getSize()->setText(qry.value(8).toString());
    animalDetailsView->getPlayful()->setText(qry.value(9).toString());
    animalDetailsView->getWinged()->setText(qry.value(10).toString());
    animalDetailsView->getCost()->setText(qry.value(11).toString());
    animalDetailsView->getShedding()->setText(qry.value(12).toString());
    animalDetailsView->getAggression()->setText(qry.value(13).toString());
    animalDetailsView->getBehaviour()->setText(qry.value(14).toString());
    animalDetailsView->getDisease()->setText(qry.value(15).toString());
    animalDetailsView->getParasite()->setText(qry.value(16).toString());
    animalDetailsView->getNovice()->setText(qry.value(17).toString());
    animalDetailsView->getEase()->setText(qry.value(18).toString());
    animalDetailsView->getEnivornment()->setText(qry.value(19).toString());
    animalDetailsView->getVocal()->setText(qry.value(20).toString());
    animalDetailsView->getclawState()->setText(qry.value(21).toString());
    animalDetailsView->show();

    this->connect(animalDetailsView,SIGNAL(updateButtonClicked()),this,SLOT(updateButtonDone()));
}

void StaffController::clientTableItemDone()
{
    clientDetailsView = new ClientDetailsView;
    QSqlQuery qry;
    qDebug()<<browseClientsView->clientTableRowString;

    qry.prepare("SELECT name,number,email,age,numberOfChildren,ageOfChildren,otherAnimals,employmentType,maritalStatus,employmentStatus,income,architectureStyle from client WHERE client_id = '"+browseClientsView->clientTableRowString+"'");

    qry.exec();
    qry.next();
    qDebug()<<qry.value(0);

    clientDetailsView->getName()->setText(qry.value(0).toString());
    clientDetailsView->getNumber()->setText(qry.value(1).toString());
    clientDetailsView->getEmail()->setText(qry.value(2).toString());
    clientDetailsView->getAge()->setText(qry.value(3).toString());
    clientDetailsView->getNumChild()->setText(qry.value(4).toString());
    clientDetailsView->getAgeChild()->setText(qry.value(5).toString());
    clientDetailsView->getOtherAnimal()->setText(qry.value(6).toString());
    clientDetailsView->getEmploymentType()->setText(qry.value(7).toString());
    clientDetailsView->getMStatus()->setText(qry.value(8).toString());
    clientDetailsView->getEStatus()->setText(qry.value(9).toString());
    clientDetailsView->getIncome()->setText(qry.value(10).toString());
    clientDetailsView->getStyle()->setText(qry.value(11).toString());
    clientDetailsView->show();
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
                                                     "'"+this->addClientView->email+"',"
                                                     "Null,Null,Null,Null,Null,Null,Null,Null,Null)");
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

void StaffController::browseClientsBackButtonDone()
{
    qDebug()<<"Client List Window: Back button pressed";

    //return to staff view from browsing animals
    this->browseClientsView->hide();
    this->staffView->show();
}

void StaffController::updateButtonDone()
{
    qDebug()<<"Animal Details Window: Update button pressed";

    bool ret = false;
    QSqlQuery qry;
    qry.prepare("UPDATE animal SET houstrained = '"+this->animalDetailsView->getHousetrained()->text()+"', specialNeeds = '"+this->animalDetailsView->getSpecial()->text()+"', lifespan = '"+this->animalDetailsView->getSpan()->text()+"', size = '"+this->animalDetailsView->getSize()->text()+"', costOfCare = '"+this->animalDetailsView->getCost()->text()+"', sheddingAmount = '"+this->animalDetailsView->getShedding()->text()+"', aggression = '"+this->animalDetailsView->getAggression()->text()+"', playfulness = '"+this->animalDetailsView->getPlayful()->text()+"', solitudialBehaviour = '"+this->animalDetailsView->getBehaviour()->text()+"', diseaseResistance = '"+this->animalDetailsView->getDisease()->text()+"', parasiticResistance = '"+this->animalDetailsView->getParasite()->text()+"', goodforNOwners = '"+this->animalDetailsView->getNovice()->text()+"', easeOfTraining = '"+this->animalDetailsView->getEase()->text()+"', environmentType = '"+this->animalDetailsView->getEnivornment()->text()+"', winged = '"+this->animalDetailsView->getWinged()->text()+"', vocal = '"+this->animalDetailsView->getVocal()->text()+"', clawState = '"+this->animalDetailsView->getclawState()->text()+"' WHERE name = '"+this->animalDetailsView->getName()->text()+"'");
    ret = qry.exec();
    if (ret){
        QMessageBox::information(this->animalDetailsView,tr("Success!"),tr("Animal Updated"));
    }
    else{
        QMessageBox::information(this->animalDetailsView,tr("Error!"),tr("Error updating field(s)"));
    }
}
