#include "stafflogin.h"
#include "ui_stafflogin.h"

StaffLogin::StaffLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffLogin)
{
    ui->setupUi(this);
    this->connect(this->ui->loginButton,SIGNAL(clicked()),this,SLOT(loginButtonSlot()));
    ui->userName->setFocus();
}

StaffLogin::~StaffLogin()
{
    delete ui;
}

//getter function for retrieving the username variable
QLineEdit* StaffLogin::getForm()
{
    return ui->userName;
}

void StaffLogin::loginButtonSlot()
{
    username = ui->userName->text();
    emit loginButtonClicked();
    qDebug()<<username;
}
