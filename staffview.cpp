#include "staffview.h"
#include "ui_staffview.h"

StaffView::StaffView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffView)
{
    ui->setupUi(this);
    this->connect(this->ui->browseButton,SIGNAL(clicked()),this,SLOT(browseButtonSlot()));
    this->connect(this->ui->addAnimalButton,SIGNAL(clicked()),this,SLOT(addAnimalButtonSlot()));
}

StaffView::~StaffView()
{
    delete ui;
}

void StaffView::browseButtonSlot()
{
    emit browseButtonClicked();
    qDebug()<<"test";
}

void StaffView::addAnimalButtonSlot()
{
    emit addAnimalButtonClicked();
}
