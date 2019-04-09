#include "animaldetailsview.h"
#include "ui_animaldetailsview.h"

AnimalDetailsView::AnimalDetailsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailsView)
{
    ui->setupUi(this);
    this->connect(this->ui->updateButton,SIGNAL(clicked()),this,SLOT(updateButtonSlot()));
}

AnimalDetailsView::~AnimalDetailsView()
{
    delete ui;
}

QLineEdit* AnimalDetailsView::getName()
{
    return ui->nameLabel;
}

QLineEdit* AnimalDetailsView::getType()
{
    return ui->typeLabel;
}

QLineEdit* AnimalDetailsView::getBreed()
{
    return ui->breedLabel;
}

QComboBox* AnimalDetailsView::getGender()
{
    return ui->genderDropdown;
}

QLineEdit* AnimalDetailsView::getAge()
{
    return ui->ageLabel;
}
QComboBox* AnimalDetailsView::getHousetrained()
{
    return ui->trainedDropdown;
}
QComboBox* AnimalDetailsView::getSpecial()
{
    return ui->specialNeedsDropdown;
}
QComboBox* AnimalDetailsView::getSpan()
{
    return ui->lifeSpanDropdown;
}
QComboBox* AnimalDetailsView::getSize()
{
    return ui->sizeDropdown;
}
QComboBox* AnimalDetailsView::getPlayful()
{
    return ui->playfulnessDropdown;
}
QComboBox* AnimalDetailsView::getCost()
{
    return ui->costDropdown;
}
QComboBox* AnimalDetailsView::getShedding()
{
    return ui->sheddingDropdown;
}
QComboBox* AnimalDetailsView::getAggression()
{
    return ui->aggressonDropdown;
}
QComboBox* AnimalDetailsView::getBehaviour()
{
    return ui->solitudeDropdown;
}
QComboBox* AnimalDetailsView::getDisease()
{
    return ui->diseaseDropdown;
}
QComboBox* AnimalDetailsView::getParasite()
{
    return ui->parasiteDropdown;
}
QComboBox* AnimalDetailsView::getNovice()
{
    return ui->noviceDropdown;
}
QComboBox* AnimalDetailsView::getEase()
{
    return ui->trainingDropdown;
}
QComboBox* AnimalDetailsView::getEnivornment()
{
    return ui->environmentDropdown;
}
QComboBox* AnimalDetailsView::getWinged()
{
    return ui->wingedDropdown;
}
QComboBox* AnimalDetailsView::getVocal()
{
    return ui->vocalDropdown;
}
QComboBox* AnimalDetailsView::getclawState()
{
    return ui->clawDropdown;
}

void AnimalDetailsView::setClient(bool clientValue)
{
    if (clientValue == true)
    {
        ui->updateButton->hide();
    }
}

void AnimalDetailsView::updateButtonSlot()
{
    emit updateButtonClicked();
}
