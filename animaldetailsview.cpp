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
