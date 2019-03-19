#include "clientcontroller.h"
#include <QApplication>

ClientController::ClientController()
{
    clientLoginButtonDone();
}

ClientController::~ClientController()
{
    qDebug()<<"destructor";
}

void ClientController::clientLoginButtonDone()
{
    clientView = new ClientView;
    clientView->show();
    this->connect(clientView,SIGNAL(browseButtonClicked()),this,SLOT(browseButtonDone()));
    this->connect(clientView,SIGNAL(clientLogoutClicked()),this,SLOT(clientLogoutDone()));
    this->connect(clientView,SIGNAL(editProfileClicked()),this,SLOT(editProfileDone()));

}

void ClientController::browseButtonDone()
{
    qDebug()<<"Main Client Window: Browse Animals button pressed";

    //user chooses to browse animals
    this->clientView->hide();
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

void ClientController::browseBackButtonDone()
{
    qDebug()<<"Animal List Window: Back button pressed";

    //return to client view from browsing animals
    this->browseView->hide();
    this->clientView->show();
}

void ClientController::tableItemDone()
{
    animalDetailsView = new AnimalDetailsView;
    QSqlQuery qry;
    /*
    //qry.prepare("SELECT name,type,breed,gender,age from animal WHERE animal_id = '"+browseView->tableRowString+"'");
    qry.prepare("SELECT name,type,breed,gender,age,houstrained,specialNeeds,lifeSpan,size,costOfCare,sheddingAmount,"
                "aggression,playfulness,solitudialBehaviour,diseaseResistance,parasiticResistance,goodforNOwners,"
                "easeOfTraining,environmentType,winged,vocal,vocal from animal WHERE animal_id = '"+browseView->tableRowString+"'");
                */
    qry.prepare("SELECT name,type,breed,gender,age,houstrained,specialNeeds,lifeSpan,size,playfulness,winged,costOfCare,sheddingAmount,"
                "aggression,solitudialBehaviour,diseaseResistance,parasiticResistance,goodforNOwners,"
                "easeOfTraining,environmentType,vocal,clawState from animal WHERE animal_id = '"+browseView->tableRowString+"'");
    qry.exec();
    qry.next();
    qDebug()<<qry.value(0);
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
    animalDetailsView->getHousetrained()->setReadOnly(true);
    animalDetailsView->getSpecial()->setText(qry.value(6).toString());
    animalDetailsView->getSpecial()->setReadOnly(true);
    animalDetailsView->getSpan()->setText(qry.value(7).toString());
    animalDetailsView->getSpan()->setReadOnly(true);
    animalDetailsView->getSize()->setText(qry.value(8).toString());
    animalDetailsView->getSize()->setReadOnly(true);
    animalDetailsView->getPlayful()->setText(qry.value(9).toString());
    animalDetailsView->getPlayful()->setReadOnly(true);
    animalDetailsView->getWinged()->setText(qry.value(10).toString());
    animalDetailsView->getWinged()->setReadOnly(true);
    animalDetailsView->getCost()->setText(qry.value(11).toString());
    animalDetailsView->getCost()->setReadOnly(true);
    animalDetailsView->getShedding()->setText(qry.value(12).toString());
    animalDetailsView->getShedding()->setReadOnly(true);
    animalDetailsView->getAggression()->setText(qry.value(13).toString());
    animalDetailsView->getAggression()->setReadOnly(true);
    animalDetailsView->getBehaviour()->setText(qry.value(14).toString());
    animalDetailsView->getBehaviour()->setReadOnly(true);
    animalDetailsView->getDisease()->setText(qry.value(15).toString());
    animalDetailsView->getDisease()->setReadOnly(true);
    animalDetailsView->getParasite()->setText(qry.value(16).toString());
    animalDetailsView->getParasite()->setReadOnly(true);
    animalDetailsView->getNovice()->setText(qry.value(17).toString());
    animalDetailsView->getNovice()->setReadOnly(true);
    animalDetailsView->getEase()->setText(qry.value(18).toString());
    animalDetailsView->getEase()->setReadOnly(true);
    animalDetailsView->getEnivornment()->setText(qry.value(19).toString());
    animalDetailsView->getEnivornment()->setReadOnly(true);
    animalDetailsView->getVocal()->setText(qry.value(20).toString());
    animalDetailsView->getVocal()->setReadOnly(true);
    animalDetailsView->getclawState()->setText(qry.value(21).toString());
    animalDetailsView->getclawState()->setReadOnly(true);
    animalDetailsView->setClient(true);
    animalDetailsView->show();
}

void ClientController::clientLogoutDone()
{
    qDebug()<<"Client has logged out";

    //staff member logouts of the system
    emit showMain();
    this->clientView->close();
}

void ClientController::editProfileDone()
{
    editDetailsView = new EditClientDetailsView;
    this->clientView->hide();
    editDetailsView->show();
    this->editDetailsView->getName()->setText(username);

    this->connect(editDetailsView,SIGNAL(editClientBackButtonClicked()),this,SLOT(editClientBackButtonDone()));
    this->connect(editDetailsView,SIGNAL(editClientAddButtonClicked()),this,SLOT(editClientAddButtonDone()));
    databasemanager* cuacsdb = databasemanager::getInstance();
    QVector<QString> v = cuacsdb->editClientGetinfo(username);
    this->editDetailsView->getNumber()->setText(v.value(0));
    this->editDetailsView->getEmail()->setText(v.value(1));
}

void ClientController::editClientBackButtonDone()
{
    qDebug()<<"Edit Client Window: Back button pressed";

    //return to client view from Edit details view
    this->editDetailsView->hide();
    this->clientView->show();
}


void ClientController::editClientAddButtonDone()
{

    qDebug()<<"Edit Client Window: Add button pressed";
    QVector<QString> v;
    v.append(this->editDetailsView->getName()->text());
    v.append(this->editDetailsView->getNumber()->text());
    v.append(this->editDetailsView->getEmail()->text());
    v.append(this->editDetailsView->getAge()->text());
    v.append(this->editDetailsView->getNumChild()->text());
    v.append(this->editDetailsView->getAgeChild()->text());
    v.append(this->editDetailsView->getOtherAnimal()->text());
    v.append(this->editDetailsView->getEmploymentType()->text());
    v.append(this->editDetailsView->getMStatus()->text());
    v.append(this->editDetailsView->getEStatus()->text());
    v.append(this->editDetailsView->getIncome()->text());
    v.append(this->editDetailsView->getStyle()->text());

    databasemanager* cuacsdb = databasemanager::getInstance();
    bool ret=cuacsdb->editClientaddInfo(v);

    if (ret){
        QMessageBox::information(this->editDetailsView,tr("Success!"),tr("Client Profile Set"));
    }
    else{
        QMessageBox::information(this->editDetailsView,tr("Error!"),tr("Error updating field(s)"));
    }



}

