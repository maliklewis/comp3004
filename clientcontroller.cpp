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
    databasemanager* cuacsdb = databasemanager::getInstance();
    qry = cuacsdb->browseAnimalsQuery();


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

    databasemanager* cuacsdb = databasemanager::getInstance();
    QVector<QString> v = cuacsdb->getAnimalinfo(browseView->tableRowString);


    qDebug()<<v.at(0);
    animalDetailsView->getName()->setText(v.at(0));
    animalDetailsView->getName()->setReadOnly(true);
    animalDetailsView->getType()->setText(v.at(1));
    animalDetailsView->getType()->setReadOnly(true);
    animalDetailsView->getBreed()->setText(v.at(2));
    animalDetailsView->getBreed()->setReadOnly(true);
    animalDetailsView->getGender()->setCurrentText(v.at(3));
    animalDetailsView->getGender()->setEnabled(false);
    animalDetailsView->getAge()->setText(v.at(4) + " years");
    animalDetailsView->getAge()->setReadOnly(true);
    animalDetailsView->getHousetrained()->setCurrentText(v.at(5));
    animalDetailsView->getHousetrained()->setEnabled(false);
    animalDetailsView->getSpecial()->setCurrentText(v.at(6));
    animalDetailsView->getSpecial()->setEnabled(false);
    animalDetailsView->getSpan()->setCurrentText(v.at(7));
    animalDetailsView->getSpan()->setEnabled(false);
    animalDetailsView->getSize()->setCurrentText(v.at(8));
    animalDetailsView->getSize()->setEnabled(false);
    animalDetailsView->getPlayful()->setCurrentText(v.at(9));
    animalDetailsView->getPlayful()->setEnabled(false);
    animalDetailsView->getWinged()->setCurrentText(v.at(10));
    animalDetailsView->getWinged()->setEnabled(false);
    animalDetailsView->getCost()->setCurrentText(v.at(11));
    animalDetailsView->getCost()->setEnabled(false);
    animalDetailsView->getShedding()->setCurrentText(v.at(12));
    animalDetailsView->getShedding()->setEnabled(false);
    animalDetailsView->getAggression()->setCurrentText(v.at(13));
    animalDetailsView->getAggression()->setEnabled(false);
    animalDetailsView->getBehaviour()->setCurrentText(v.at(14));
    animalDetailsView->getBehaviour()->setEnabled(false);
    animalDetailsView->getDisease()->setCurrentText(v.at(15));
    animalDetailsView->getDisease()->setEnabled(false);
    animalDetailsView->getParasite()->setCurrentText(v.at(16));
    animalDetailsView->getParasite()->setEnabled(false);
    animalDetailsView->getNovice()->setCurrentText(v.at(17));
    animalDetailsView->getNovice()->setEnabled(false);
    animalDetailsView->getEase()->setCurrentText(v.at(18));
    animalDetailsView->getEase()->setEnabled(false);
    animalDetailsView->getEnivornment()->setCurrentText(v.at(19));
    animalDetailsView->getEnivornment()->setEnabled(false);
    animalDetailsView->getVocal()->setCurrentText(v.at(20));
    animalDetailsView->getVocal()->setEnabled(false);
    animalDetailsView->getclawState()->setCurrentText(v.at(21));
    animalDetailsView->getclawState()->setEnabled(false);
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
    this->connect(editDetailsView,SIGNAL(editClientPrefButtonClicked()),this,SLOT(editClientPrefButtonDone()));
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

void ClientController::editClientPrefButtonDone()
{
    clientPrefView = new ClientPreferencesView;
    clientPrefView->show();
    //this->connect(clientPrefView,saveButtonClicked(),)
    this->connect(clientPrefView,SIGNAL(saveButtonClicked()),this,SLOT(clientPrefSaveButtonDone()));
}

void ClientController::clientPrefSaveButtonDone()
{
    qDebug()<<"Edit Client Preference Window: Save button pressed";
    QVector<QString> v;
    v.append(this->clientPrefView->getPAnimalType());
    v.append(this->clientPrefView->getPAnimalBreed());
    v.append(this->clientPrefView->getAgeRange());
    v.append(this->clientPrefView->getPAnimalType());
    v.append(this->clientPrefView->getPrefEnvType());
    v.append(this->clientPrefView->getVetFees());
    v.append(this->clientPrefView->getKidFriendly());
    v.append(this->clientPrefView->getEaseTrain());
    v.append(this->clientPrefView->getHealthCon());
    v.append(this->clientPrefView->getPrefSize());
    v.append(this->editDetailsView->getName()->text());

    databasemanager* cuacsdb = databasemanager::getInstance();
    bool ret=cuacsdb->editClientPrefInfo(v);

    if (ret){
        QMessageBox::information(this->clientPrefView,tr("Success!"),tr("Preferences Set"));
    }
    else{
        QMessageBox::information(this->clientPrefView,tr("Error!"),tr("Error setting preferences"));
    }
}

