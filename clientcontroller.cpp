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
    //qry.prepare("SELECT name,type,breed,gender,age from animal WHERE animal_id = '"+browseView->tableRowString+"'");
    qry.prepare("SELECT name,type,breed,gender,age,houstrained,specialNeeds,lifeSpan,size,costOfCare,sheddingAmount,"
                "aggression,playfulness,solitudialBehaviour,diseaseResistance,parasiticResistance,goodforNOwners,"
                "easeOfTraining,environmentType from animal WHERE animal_id = '"+browseView->tableRowString+"'");
    qry.exec();
    qry.next();
    qDebug()<<qry.value(0);
    animalDetailsView->getName()->setText(qry.value(0).toString());
    animalDetailsView->getType()->setText(qry.value(1).toString());
    animalDetailsView->getBreed()->setText(qry.value(2).toString());
    animalDetailsView->getGender()->setText(qry.value(3).toString());
    animalDetailsView->getAge()->setText(qry.value(4).toString() + " years");
    animalDetailsView->getHousetrained()->setText(qry.value(5).toString());
    animalDetailsView->getSpecial()->setText(qry.value(6).toString());
    animalDetailsView->getSpan()->setText(qry.value(7).toString());
    animalDetailsView->getSize()->setText(qry.value(8).toString());
    animalDetailsView->getPlayful()->setText(qry.value(9).toString());
    animalDetailsView->getCost()->setText(qry.value(10).toString());
    animalDetailsView->getShedding()->setText(qry.value(11).toString());
    animalDetailsView->getAggression()->setText(qry.value(12).toString());
    animalDetailsView->getBehaviour()->setText(qry.value(13).toString());
    animalDetailsView->getDisease()->setText(qry.value(14).toString());
    animalDetailsView->getParasite()->setText(qry.value(15).toString());
    animalDetailsView->getNovice()->setText(qry.value(16).toString());
    animalDetailsView->getEase()->setText(qry.value(17).toString());
    animalDetailsView->getEnivornment()->setText(qry.value(18).toString());
    animalDetailsView->show();
}

void ClientController::clientLogoutDone()
{
    qDebug()<<"Client has logged out";

    //staff member logouts of the system
    emit showMain();
    this->clientView->close();
}
