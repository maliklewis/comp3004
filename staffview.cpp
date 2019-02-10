#include "staffview.h"
#include "ui_staffview.h"

StaffView::StaffView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffView)
{
    ui->setupUi(this);
    this->connect(this->ui->browseButton,SIGNAL(clicked()),this,SLOT(browseButtonSlot()));

    this->connect(this->ui->logoutButton,SIGNAL(clicked()),this,SLOT(staffLogoutButtonSlot()));



}

StaffView::~StaffView()
{
    delete ui;
}

void StaffView::browseButtonSlot()
{
    emit browseButtonClicked();

}

void StaffView::staffLogoutButtonSlot()
{
    emit staffLogoutClicked();
}

