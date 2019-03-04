#include "clientlogin.h"
#include "ui_clientlogin.h"

ClientLogin::ClientLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientLogin)
{
    ui->setupUi(this);
    this->connect(this->ui->loginButton,SIGNAL(clicked()),this,SLOT(loginButtonSlot()));

}

ClientLogin::~ClientLogin()
{
    delete ui;
}

void ClientLogin::loginButtonSlot()
{
    username = ui->userName->text();
    emit clientLoginButtonClicked();
    qDebug()<<username;
}
