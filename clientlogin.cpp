#include "clientlogin.h"
#include "ui_clientlogin.h"

ClientLogin::ClientLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientLogin)
{
    ui->setupUi(this);
}

ClientLogin::~ClientLogin()
{
    delete ui;
}
