#include "editclientdetailsview.h"
#include "ui_editclientdetailsview.h"

EditClientDetailsView::EditClientDetailsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::EditClientDetailsView)
{
    ui->setupUi(this);
    this->connect(this->ui->clientBackButton,SIGNAL(clicked()),this,SLOT(editClientBackButtonSlot()));
    this->connect(this->ui->clientAddButton,SIGNAL(clicked()),this,SLOT(editClientAddButtonSlot()));
    this->connect(this->ui->prefButton,SIGNAL(clicked()),this,SLOT(editClientPrefButtonSlot()));
    ui->nameValue->setReadOnly(true);
    ui->numberValue->setReadOnly(true);
    ui->emailValue->setReadOnly(true);
    ui->ageValue->setFocus();
}

EditClientDetailsView::~EditClientDetailsView()
{
    delete ui;
}

QLineEdit* EditClientDetailsView::getName()
{
    return ui->nameValue;
}
QLineEdit* EditClientDetailsView::getAge()
{
    return ui->ageValue;
}

QLineEdit* EditClientDetailsView::getEmail()
{
    return ui->emailValue;
}

QLineEdit* EditClientDetailsView::getEmploymentType()
{
    return ui->employmenttypeValue;
}

QLineEdit* EditClientDetailsView::getEStatus()
{
    return ui->employmentstatusValue;
}

QLineEdit* EditClientDetailsView::getMStatus()
{
    return ui->maritalstatusValue;
}

QLineEdit* EditClientDetailsView::getNumber()
{
    return ui->numberValue;
}

QLineEdit* EditClientDetailsView::getNumChild()
{
    return ui->numofchildrenValue;
}

QLineEdit* EditClientDetailsView::getAgeChild()
{
    return ui->ageofchildrenValue;
}

QLineEdit* EditClientDetailsView::getOtherAnimal()
{
    return ui->otheranimalsValue;
}

QLineEdit* EditClientDetailsView::getIncome()
{
    return ui->incomeValue;
}

QLineEdit* EditClientDetailsView::getStyle()
{
    return ui->architecturalstyleValue;
}

void EditClientDetailsView::editClientBackButtonSlot()
{
   emit editClientBackButtonClicked();
}

void EditClientDetailsView::editClientAddButtonSlot()
{
    emit editClientAddButtonClicked();
}

void EditClientDetailsView::editClientPrefButtonSlot()
{
    emit editClientPrefButtonClicked();
}
