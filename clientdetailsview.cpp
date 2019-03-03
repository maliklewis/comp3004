#include "clientdetailsview.h"
#include "ui_clientdetailsview.h"

ClientDetailsView::ClientDetailsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailsView)
{
    ui->setupUi(this);
}

ClientDetailsView::~ClientDetailsView()
{
    delete ui;
}

QLabel* ClientDetailsView::getName()
{
    return ui->nameValue;
}
QLabel* ClientDetailsView::getAge()
{
    return ui->ageValue;
}

QLabel* ClientDetailsView::getEmail()
{
    return ui->emailValue;
}

QLabel* ClientDetailsView::getEmploymentType()
{
    return ui->empTypeValue;
}

QLabel* ClientDetailsView::getEStatus()
{
    return ui->EstatusValue;
}

QLabel* ClientDetailsView::getMStatus()
{
    return ui->MStatusValue;
}

QLabel* ClientDetailsView::getNumber()
{
    return ui->numberValue;
}

QLabel* ClientDetailsView::getNumChild()
{
    return ui->numChildValue;
}

QLabel* ClientDetailsView::getAgeChild()
{
    return ui->childAgeValue;
}

QLabel* ClientDetailsView::getOtherAnimal()
{
    return ui->otherValue;
}

QLabel* ClientDetailsView::getIncome()
{
    return ui->incomeValue;
}

QLabel* ClientDetailsView::getStyle()
{
    return ui->styleValue;
}
