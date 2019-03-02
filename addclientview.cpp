#include "addclientview.h"
#include "ui_addclientview.h"

addclientview::addclientview(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::addclientview)
{
    ui->setupUi(this);
}

addclientview::~addclientview()
{
    delete ui;
}
