#include "clientview.h"
#include "ui_clientview.h"

ClientView::ClientView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientView)
{
    ui->setupUi(this);
}

ClientView::~ClientView()
{
    delete ui;
}
