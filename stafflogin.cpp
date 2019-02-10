#include "stafflogin.h"
#include "ui_stafflogin.h"

StaffLogin::StaffLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffLogin)
{
    ui->setupUi(this);
    this->connect(this->ui->loginButton,SIGNAL(clicked()),this,SLOT(loginButtonSlot()));
}

StaffLogin::~StaffLogin()
{
    delete ui;
}

void StaffLogin::loginButtonSlot()
{
    username = ui->userName->text();
    qDebug()<<username;
    emit loginButtonClicked();
}
