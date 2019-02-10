#include "browseanimals.h"
#include "ui_browseanimals.h"

BrowseAnimals::BrowseAnimals(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseAnimals)
{
    ui->setupUi(this);
}

BrowseAnimals::~BrowseAnimals()
{
    delete ui;
}
