#include "animaldetailsview.h"
#include "ui_animaldetailsview.h"

AnimalDetailsView::AnimalDetailsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AnimalDetailsView)
{
    ui->setupUi(this);
}

AnimalDetailsView::~AnimalDetailsView()
{
    delete ui;
}

QLabel* AnimalDetailsView::getName()
{
    return ui->nameLabel;
}

QLabel* AnimalDetailsView::getType()
{
    return ui->typeLabel;
}

QLabel* AnimalDetailsView::getBreed()
{
    return ui->breedLabel;
}

QLabel* AnimalDetailsView::getGender()
{
    return ui->genderLabel;
}

QLabel* AnimalDetailsView::getAge()
{
    return ui->ageLabel;
}
QLabel* AnimalDetailsView::getHousetrained()
{
    return ui->TrainedLabel;
}
QLabel* AnimalDetailsView::getSpecial()
{
    return ui->specialNeedsLabel;
}
QLabel* AnimalDetailsView::getSpan()
{
    return ui->lifeSpanLabel;
}
QLabel* AnimalDetailsView::getSize()
{
    return ui->sizeLabel;
}
QLabel* AnimalDetailsView::getPlayful()
{
    return ui->playfulnessLabel;
}
QLabel* AnimalDetailsView::getCost()
{
    return ui->costLabel;
}
QLabel* AnimalDetailsView::getShedding()
{
    return ui->sheddingLabel;
}
QLabel* AnimalDetailsView::getAggression()
{
    return ui->aggressionLabel;
}
QLabel* AnimalDetailsView::getBehaviour()
{
    return ui->solitudeLabel;
}
QLabel* AnimalDetailsView::getDisease()
{
    return ui->diseaseLabel;
}
QLabel* AnimalDetailsView::getParasite()
{
    return ui->parasiteLabel;
}
QLabel* AnimalDetailsView::getNovice()
{
    return ui->noviceLabel;
}
QLabel* AnimalDetailsView::getEase()
{
    return ui->trainingLabel;
}
QLabel* AnimalDetailsView::getEnivornment()
{
    return ui->enivronmentLabel;
}
QLabel* AnimalDetailsView::getWinged()
{
    return ui->wingedLabel;
}
QLabel* AnimalDetailsView::getVocal()
{
    return ui->vocalLabel;
}
QLabel* AnimalDetailsView::getclawState()
{
    return ui->clawLabel;
}
