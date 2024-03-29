#include "addanimalview.h"
#include "ui_addanimalview.h"

AddAnimalView::AddAnimalView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAnimalView)
{
    ui->setupUi(this);
    this->connect(this->ui->animalAddButton,SIGNAL(clicked()),this,SLOT(insertAnimalButtonSlot()));
    this->connect(this->ui->backButton,SIGNAL(clicked()),this,SLOT(insertAnimalBackButtonSlot()));
}

AddAnimalView::~AddAnimalView()
{
    delete ui;
}


void AddAnimalView::insertAnimalButtonSlot()
{
    //set ui variables for controller access
    name   = ui->nameValue->text();
    age    = ui->ageValue->text();
    type   = ui->typeDropdown->currentText();
    breed  = ui->breedDropdown->currentText();
    gender = ui->genderDropdown->currentText();
    housetrained = ui->housetrainedDropdown->currentText();
    specialneeds = ui->specialNeedsDropdown->currentText();
    lifespan = ui->lifespanDropwdown->currentText();
    size = ui->sizeDropdown->currentText();
    carecost = ui->costDropdown->currentText();
    shedAmount = ui->sheddingDropwdown->currentText();
    aggression = ui->aggressionDropdown->currentText();
    playfulness = ui->playfulnessDropdown->currentText();
    solitudialBehavior = ui->solittudialBehaviourDropdown->currentText();
    diseaseResistance = ui->dResistanceDropdown->currentText();
    parasiticResistance = ui->pResistanceDropdown->currentText();
    goodForNowners = ui->noviceOwnerDropdown->currentText();
    trainingEase = ui->easeofTraingDropdown->currentText();
    environmentType = ui->environmentDropdown->currentText();
    winged = ui->wingedDropdown->currentText();
    vocal = ui->vocalDropdown->currentText();
    clawState = ui->clawDropdown->currentText();

    emit insertAnimalButtonClicked();
}

void AddAnimalView::insertAnimalBackButtonSlot()
{
    emit insertAnimalBackButtonClicked();
}

void AddAnimalView::on_typeDropdown_currentTextChanged(const QString &arg1)
{
    //set breed dropdown options based on animal type
    if (arg1 == "Dog"){
        ui->breedDropdown->clear();
        ui->breedDropdown->addItem("Pitbull");
        ui->breedDropdown->addItem("Chihuahua");
        ui->breedDropdown->addItem("Beagle");
        ui->breedDropdown->addItem("German Shepherd");
        ui->breedDropdown->addItem("Poodle");
        ui->breedDropdown->addItem("Pug");
        ui->breedDropdown->addItem("Husky");
        ui->breedDropdown->addItem("Great Dane");
        ui->breedDropdown->addItem("Greyhound");
        ui->lifespanDropwdown->clear();
        ui->lifespanDropwdown->addItem("14 Years");
    }
    else if (arg1 == "Cat") {
        ui->breedDropdown->clear();
        ui->breedDropdown->addItem("Munchkin");
        ui->breedDropdown->addItem("Persian");
        ui->breedDropdown->addItem("Bengal");
        ui->breedDropdown->addItem("Egyptian");
        ui->breedDropdown->addItem("Himalayan");
        ui->lifespanDropwdown->clear();
        ui->lifespanDropwdown->addItem("15 Years");
    }
    else if (arg1 == "Bird"){
        ui->breedDropdown->clear();
        ui->breedDropdown->addItem("Parrot");
        ui->breedDropdown->addItem("Cockatoo");
        ui->breedDropdown->addItem("Lovebird");
        ui->breedDropdown->addItem("Canary");
        ui->breedDropdown->addItem("Dove");
        ui->lifespanDropwdown->clear();
        ui->lifespanDropwdown->addItem("20 Years");
    }
}

void AddAnimalView::on_easeofTraingDropdown_currentTextChanged(const QString &arg1)
{
    if (arg1 == "Low"){
        ui->vocalDropdown->setCurrentText("High");
    }
    else if (arg1 == "Medium"){
        ui->vocalDropdown->setCurrentText("Medium");
    }
    else if (arg1 == "High"){
        ui->vocalDropdown->setCurrentText("Low");
    }
}
