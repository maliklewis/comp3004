#include "stafflogin.h"
#include "ui_stafflogin.h"

StaffLogin::StaffLogin(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffLogin)
{
    ui->setupUi(this);
}

StaffLogin::~StaffLogin()
{
    delete ui;
}
