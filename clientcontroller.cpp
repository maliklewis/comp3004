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
    //staffView = new StaffView;
    //staffView->show();
    clientView = new ClientView;
    clientView->show();
    this->connect(clientView,SIGNAL(browseButtonClicked()),this,SLOT(browseButtonDone()));
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

    //this->connect(browseView,SIGNAL(browseBackButtonClicked()),this,SLOT(browseBackButtonDone()));
    this->connect(browseView,SIGNAL(tableItemClicked()),this,SLOT(tableItemDone()));
}

void ClientController::tableItemDone()
{
    //browseView->tableRow;
    animalDetailsView = new AnimalDetailsView;
    QSqlQuery qry;

    qry.prepare("SELECT name,type,breed,gender,age from animal WHERE animal_id = '"+browseView->tableRowString+"'");
    qry.exec();
    qry.next();
    qDebug()<<qry.value(0);
    animalDetailsView->getName()->setText(qry.value(0).toString());
    animalDetailsView->getType()->setText(qry.value(1).toString());
    animalDetailsView->getBreed()->setText(qry.value(2).toString());
    animalDetailsView->getGender()->setText(qry.value(3).toString());
    animalDetailsView->getAge()->setText(qry.value(4).toString() + " years");
    animalDetailsView->show();
}
