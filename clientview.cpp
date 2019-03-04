#include "clientview.h"
#include "ui_clientview.h"

ClientView::ClientView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientView)
{
    ui->setupUi(this);
    this->connect(this->ui->browseAnimalsButton,SIGNAL(clicked()),this,SLOT(browseButtonSlot()));
}

ClientView::~ClientView()
{
    delete ui;
}

void ClientView::browseButtonSlot()
{
    emit browseButtonClicked();
}
