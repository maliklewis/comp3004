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
    databasemanager* cuacsdb = databasemanager::getInstance();
    qry = cuacsdb->browseAnimalsQuery();
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
   /* qry.prepare("Select name, number, email from client");
    qry.exec();*/
    databasemanager* cuacsdb = databasemanager::getInstance();
    qry = cuacsdb->browseClientsQuery();

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
    QVector<QString> v;

    QSqlQuery qry;
    if (this->addAnimalView->name != "" && this->addAnimalView->age != ""){
        v.append(this->addAnimalView->name);
        v.append(this->addAnimalView->type);
        v.append(this->addAnimalView->breed);
        v.append(this->addAnimalView->gender);
        v.append(this->addAnimalView->age);
        v.append(this->addAnimalView->housetrained);
        v.append(this->addAnimalView->specialneeds);
        v.append(this->addAnimalView->lifespan);
        v.append(this->addAnimalView->size);
        v.append(this->addAnimalView->carecost);
        v.append(this->addAnimalView->shedAmount);
        v.append(this->addAnimalView->aggression);
        v.append(this->addAnimalView->playfulness);
        v.append(this->addAnimalView->solitudialBehavior);
        v.append(this->addAnimalView->diseaseResistance);
        v.append(this->addAnimalView->parasiticResistance);
        v.append(this->addAnimalView->goodForNowners);
        v.append(this->addAnimalView->trainingEase);
        v.append(this->addAnimalView->environmentType);
        v.append(this->addAnimalView->winged);
        v.append(this->addAnimalView->vocal);
        v.append(this->addAnimalView->clawState);

        databasemanager* cuacsdb = databasemanager::getInstance();
        ret=cuacsdb->insertAnimalquery(v);
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
    animalDetailsView = new AnimalDetailsView;
    QSqlQuery qry;
    databasemanager* cuacsdb = databasemanager::getInstance();
    QVector<QString> v = cuacsdb->getAnimalinfo(browseView->tableRowString);


    qDebug()<<v.at(0);
    animalDetailsView->getName()->setText(v.at(0));
    animalDetailsView->getName()->setReadOnly(true);
    animalDetailsView->getType()->setText(v.at(1));
    animalDetailsView->getType()->setReadOnly(true);
    animalDetailsView->getBreed()->setText(v.at(2));
    animalDetailsView->getBreed()->setReadOnly(true);
    animalDetailsView->getGender()->setText(v.at(3));
    animalDetailsView->getGender()->setReadOnly(true);
    animalDetailsView->getAge()->setText(v.at(4) + " years");
    animalDetailsView->getAge()->setReadOnly(true);
    animalDetailsView->getHousetrained()->setText(v.at(5));

    animalDetailsView->getSpecial()->setText(v.at(6));

    animalDetailsView->getSpan()->setText(v.at(7));

    animalDetailsView->getSize()->setText(v.at(8));

    animalDetailsView->getPlayful()->setText(v.at(9));

    animalDetailsView->getWinged()->setText(v.at(10));

    animalDetailsView->getCost()->setText(v.at(11));

    animalDetailsView->getShedding()->setText(v.at(12));

    animalDetailsView->getAggression()->setText(v.at(13));

    animalDetailsView->getBehaviour()->setText(v.at(14));

    animalDetailsView->getDisease()->setText(v.at(15));

    animalDetailsView->getParasite()->setText(v.at(16));

    animalDetailsView->getNovice()->setText(v.at(17));

    animalDetailsView->getEase()->setText(v.at(18));

    animalDetailsView->getEnivornment()->setText(v.at(19));

    animalDetailsView->getVocal()->setText(v.at(20));

    animalDetailsView->getclawState()->setText(v.at(21));


    animalDetailsView->show();
    this->connect(animalDetailsView,SIGNAL(updateButtonClicked()),this,SLOT(updateButtonDone()));
}

void StaffController::clientTableItemDone()
{
    clientDetailsView = new ClientDetailsView;
    /*QSqlQuery qry;
    qDebug()<<browseClientsView->clientTableRowString;

    qry.prepare("SELECT name,number,email,age,numberOfChildren,ageOfChildren,otherAnimals,employmentType,maritalStatus,employmentStatus,income,architectureStyle from client WHERE client_id = '"+browseClientsView->clientTableRowString+"'");

    qry.exec();
    qry.next();*/
    databasemanager* cuacsdb = databasemanager::getInstance();
    QVector<QString> v = cuacsdb->getClientinfo(browseClientsView->clientTableRowString);

    qDebug()<<v.at(0);

    clientDetailsView->getName()->setText(v.at(0));
    clientDetailsView->getNumber()->setText(v.at(1));
    clientDetailsView->getEmail()->setText(v.at(2));
    clientDetailsView->getAge()->setText(v.at(3));
    clientDetailsView->getNumChild()->setText(v.at(4));
    clientDetailsView->getAgeChild()->setText(v.at(5));
    clientDetailsView->getOtherAnimal()->setText(v.at(6));
    clientDetailsView->getEmploymentType()->setText(v.at(7));
    clientDetailsView->getMStatus()->setText(v.at(8));
    clientDetailsView->getEStatus()->setText(v.at(9));
    clientDetailsView->getIncome()->setText(v.at(10));
    clientDetailsView->getStyle()->setText(v.at(11));
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
    QVector<QString> v;

    QSqlQuery qry;
    if (this->addClientView->name != "" && this->addClientView->number != "" && this->addClientView->email != ""){
        /*qry.prepare("INSERT INTO client VALUES (Null,'"+this->addClientView->name+"',"
                                                     "'"+this->addClientView->number+"',"
                                                     "'"+this->addClientView->email+"',"
                                                     "Null,Null,Null,Null,Null,Null,Null,Null,Null)");
        ret = qry.exec();*/

        v.append(this->addClientView->name);
        v.append(this->addClientView->number);
        v.append(this->addClientView->email);




        databasemanager* cuacsdb = databasemanager::getInstance();
        ret=cuacsdb->insertClientquery(v);
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
    QVector<QString> v;
    bool ret = false;
    QSqlQuery qry;
    /*qry.prepare("UPDATE animal SET houstrained = '"+this->animalDetailsView->getHousetrained()->text()+"', specialNeeds = '"+this->animalDetailsView->getSpecial()->text()+"', lifespan = '"+this->animalDetailsView->getSpan()->text()+"', size = '"+this->animalDetailsView->getSize()->text()+"', costOfCare = '"+this->animalDetailsView->getCost()->text()+"', sheddingAmount = '"+this->animalDetailsView->getShedding()->text()+"', aggression = '"+this->animalDetailsView->getAggression()->text()+"', playfulness = '"+this->animalDetailsView->getPlayful()->text()+"', solitudialBehaviour = '"+this->animalDetailsView->getBehaviour()->text()+"', diseaseResistance = '"+this->animalDetailsView->getDisease()->text()+"', parasiticResistance = '"+this->animalDetailsView->getParasite()->text()+"', goodforNOwners = '"+this->animalDetailsView->getNovice()->text()+"', easeOfTraining = '"+this->animalDetailsView->getEase()->text()+"', environmentType = '"+this->animalDetailsView->getEnivornment()->text()+"', winged = '"+this->animalDetailsView->getWinged()->text()+"', vocal = '"+this->animalDetailsView->getVocal()->text()+"', clawState = '"+this->animalDetailsView->getclawState()->text()+"' WHERE name = '"+this->animalDetailsView->getName()->text()+"'");
    ret = qry.exec();*/
    v.append(this->animalDetailsView->getHousetrained()->text());
    v.append(this->animalDetailsView->getSpecial()->text());
    v.append(this->animalDetailsView->getSpan()->text());
    v.append(this->animalDetailsView->getSize()->text());
    v.append(this->animalDetailsView->getCost()->text());
    v.append(this->animalDetailsView->getShedding()->text());
    v.append(this->animalDetailsView->getAggression()->text());
    v.append(this->animalDetailsView->getPlayful()->text());
    v.append(this->animalDetailsView->getBehaviour()->text());
    v.append(this->animalDetailsView->getDisease()->text());
    v.append(this->animalDetailsView->getParasite()->text());
    v.append(this->animalDetailsView->getNovice()->text());
    v.append(this->animalDetailsView->getEase()->text());
    v.append(this->animalDetailsView->getEnivornment()->text());
    v.append(this->animalDetailsView->getWinged()->text());
    v.append(this->animalDetailsView->getVocal()->text());
    v.append(this->animalDetailsView->getclawState()->text());
    v.append(this->animalDetailsView->getName()->text());

    databasemanager* cuacsdb = databasemanager::getInstance();
    ret=cuacsdb->updateAnimalquery(v);


    if (ret){
        QMessageBox::information(this->animalDetailsView,tr("Success!"),tr("Animal Updated"));
    }
    else{
        QMessageBox::information(this->animalDetailsView,tr("Error!"),tr("Error updating field(s)"));
    }
}
