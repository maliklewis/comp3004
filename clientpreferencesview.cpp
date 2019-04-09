#include "clientpreferencesview.h"
#include "ui_clientpreferencesview.h"

ClientPreferencesView::ClientPreferencesView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientPreferencesView)
{
    ui->setupUi(this);
    this->connect(this->ui->saveButton,SIGNAL(clicked()),this,SLOT(saveButtonSlot()));
}

ClientPreferencesView::~ClientPreferencesView()
{
    delete ui;
}

QString ClientPreferencesView::getPAnimalType()
{
    return ui->typeDropdown->currentText();
}

QString ClientPreferencesView::getPAnimalBreed()
{
    return ui->breedDropdown->currentText();
}

QString ClientPreferencesView::getAgeRange()
{
    return ui->ageDropdown->currentText();
}

QString ClientPreferencesView::getPrefEnvType()
{
    return ui->envTypeDropdown->currentText();
}

QString ClientPreferencesView::getVetFees()
{
    return ui->vetFeesDropdown->currentText();
}

QString ClientPreferencesView::getKidFriendly()
{
    return ui->kidFriendlyDropdown->currentText();
}

QString ClientPreferencesView::getEaseTrain()
{
    return ui->easeDropdown->currentText();
}

QString ClientPreferencesView::getHealthCon()
{
    return ui->specialNeedsDropdown->currentText();
}

QString ClientPreferencesView::getPrefSize()
{
    return ui->sizeDropdown->currentText();
}


void ClientPreferencesView::saveButtonSlot()
{
    emit saveButtonClicked();
}

void ClientPreferencesView::on_typeDropdown_currentTextChanged(const QString &arg1)
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
        ui->ageDropdown->clear();
        ui->ageDropdown->addItem("0.6-2");
        ui->ageDropdown->addItem("3-6");
        ui->ageDropdown->addItem("7-14");
        ui->ageDropdown->addItem("14+");
    }
    else if (arg1 == "Cat") {
        ui->breedDropdown->clear();
        ui->breedDropdown->addItem("Munchkin");
        ui->breedDropdown->addItem("Persian");
        ui->breedDropdown->addItem("Bengal");
        ui->breedDropdown->addItem("Egyptian");
        ui->breedDropdown->addItem("Himalayan");
        ui->ageDropdown->clear();
        ui->ageDropdown->addItem("0.6-2");
        ui->ageDropdown->addItem("3-6");
        ui->ageDropdown->addItem("7-15");
        ui->ageDropdown->addItem("15+");
    }
    else if (arg1 == "Bird"){
        ui->breedDropdown->clear();
        ui->breedDropdown->addItem("Parrot");
        ui->breedDropdown->addItem("Cockatoo");
        ui->breedDropdown->addItem("Lovebird");
        ui->breedDropdown->addItem("Canary");
        ui->breedDropdown->addItem("Dove");
        ui->ageDropdown->clear();
        ui->ageDropdown->addItem("1-5");
        ui->ageDropdown->addItem("6-10");
        ui->ageDropdown->addItem("11-20");
        ui->ageDropdown->addItem("21+");
    }
}
