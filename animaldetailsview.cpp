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

QLineEdit* AnimalDetailsView::getGender()
{
    return ui->genderLabel;
}

QLineEdit* AnimalDetailsView::getAge()
{
    return ui->ageLabel;
}
QLineEdit* AnimalDetailsView::getHousetrained()
{
    return ui->trainedLabel;
}
QLineEdit* AnimalDetailsView::getSpecial()
{
    return ui->specialNeedsLabel;
}
QLineEdit* AnimalDetailsView::getSpan()
{
    return ui->lifeSpanLabel;
}
QLineEdit* AnimalDetailsView::getSize()
{
    return ui->sizeLabel;
}
QLineEdit* AnimalDetailsView::getPlayful()
{
    return ui->playfulnessLabel;
}
QLineEdit* AnimalDetailsView::getCost()
{
    return ui->costLabel;
}
QLineEdit* AnimalDetailsView::getShedding()
{
    return ui->sheddingLabel;
}
QLineEdit* AnimalDetailsView::getAggression()
{
    return ui->aggressionLabel;
}
QLineEdit* AnimalDetailsView::getBehaviour()
{
    return ui->solitudeLabel;
}
QLineEdit* AnimalDetailsView::getDisease()
{
    return ui->diseaseLabel;
}
QLineEdit* AnimalDetailsView::getParasite()
{
    return ui->parasiteLabel;
}
QLineEdit* AnimalDetailsView::getNovice()
{
    return ui->noviceLabel;
}
QLineEdit* AnimalDetailsView::getEase()
{
    return ui->trainingLabel;
}
QLineEdit* AnimalDetailsView::getEnivornment()
{
    return ui->environmentLabel;
}
QComboBox* AnimalDetailsView::getWinged()
{
    return ui->wingedDropdown;
}
QLineEdit* AnimalDetailsView::getVocal()
{
    return ui->vocalLabel;
}
QLineEdit* AnimalDetailsView::getclawState()
{
    return ui->clawLabel;
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
