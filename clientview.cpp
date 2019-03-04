#include "clientview.h"
#include "ui_clientview.h"

ClientView::ClientView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientView)
{
    ui->setupUi(this);
    this->connect(this->ui->browseAnimalsButton,SIGNAL(clicked()),this,SLOT(browseButtonSlot()));
    this->connect(this->ui->logoutButton,SIGNAL(clicked()),this,SLOT(clientLogoutButtonSlot()));
}

ClientView::~ClientView()
{
    delete ui;
}

void ClientView::browseButtonSlot()
{
    emit browseButtonClicked();
}

void ClientView::clientLogoutButtonSlot()
{
    emit clientLogoutClicked();
}
