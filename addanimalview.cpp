#include "addanimalview.h"
#include "ui_addanimalview.h"

AddAnimalView::AddAnimalView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AddAnimalView)
{
    ui->setupUi(this);
}

AddAnimalView::~AddAnimalView()
{
    delete ui;
}


