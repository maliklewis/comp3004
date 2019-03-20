#include "staffview.h"
#include "ui_staffview.h"

StaffView::StaffView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffView)
{
    ui->setupUi(this);
    this->connect(this->ui->browseAnimalsButton,SIGNAL(clicked()),this,SLOT(browseButtonSlot()));
    this->connect(this->ui->browseClientsButton,SIGNAL(clicked()),this,SLOT(browseClientsButtonSlot()));
    this->connect(this->ui->addAnimalButton,SIGNAL(clicked()),this,SLOT(addAnimalButtonSlot()));
    this->connect(this->ui->logoutButton,SIGNAL(clicked()),this,SLOT(staffLogoutButtonSlot()));
    this->connect(this->ui->addClientButton,SIGNAL(clicked()),this,SLOT(addClientButtonSlot()));
    this->connect(this->ui->algorithmButton,SIGNAL(clicked()),this,SLOT(algorithmButtonSlot()));
}

StaffView::~StaffView()
{
    delete ui;
}

void StaffView::browseButtonSlot()
{
    emit browseButtonClicked();
}
void StaffView::browseClientsButtonSlot()
{
    emit browseClientsButtonClicked();
}

void StaffView::staffLogoutButtonSlot()
{
    emit staffLogoutClicked();
}

void StaffView::addAnimalButtonSlot()
{
    emit addAnimalButtonClicked();
}
void StaffView::addClientButtonSlot()
{
    emit addClientButtonClicked();
}
void StaffView::algorithmButtonSlot()
{
    emit algorithmButtonClicked();
}
