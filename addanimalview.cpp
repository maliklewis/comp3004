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
    name   = ui->nameValue->text();
    age    = ui->ageValue->text();
    type   = ui->typeDropdown->currentText();
    breed  = ui->breedDropdown->currentText();
    gender = ui->genderDropdown->currentText();

    emit insertAnimalButtonClicked();
}

void AddAnimalView::insertAnimalBackButtonSlot()
{
    emit insertAnimalBackButtonClicked();
}

void AddAnimalView::on_typeDropdown_currentTextChanged(const QString &arg1)
{
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
    }
    else if (arg1 == "Cat") {
        ui->breedDropdown->clear();
        ui->breedDropdown->addItem("Munchkin");
        ui->breedDropdown->addItem("Persian");
        ui->breedDropdown->addItem("Bengal");
        ui->breedDropdown->addItem("Egyptian");
        ui->breedDropdown->addItem("Himalayan");
    }
    else if (arg1 == "Bird"){
        ui->breedDropdown->clear();
        ui->breedDropdown->addItem("Parrot");
        ui->breedDropdown->addItem("Cockatoo");
        ui->breedDropdown->addItem("Lovebird");
        ui->breedDropdown->addItem("Canary");
        ui->breedDropdown->addItem("Dove");
    }
}
