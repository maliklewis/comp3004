#include "addclientview.h"
#include "ui_addclientview.h"

addclientview::addclientview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addclientview)
{
    ui->setupUi(this);
    this->connect(this->ui->clientAddButton,SIGNAL(clicked()),this,SLOT(insertClientButtonSlot()));
    this->connect(this->ui->clientBackButton,SIGNAL(clicked()),this,SLOT(insertClientBackButtonSlot()));

}

addclientview::~addclientview()
{
    delete ui;
}

void addclientview::insertClientButtonSlot()
{
    //set ui variables for controller access
    name   = ui->nameValue->text();
    number = ui->numberValue->text();
    email  = ui->emailValue->text();

    emit insertClientButtonClicked();
}
void addclientview::insertClientBackButtonSlot()
{
    emit insertClientBackButtonClicked();
}
