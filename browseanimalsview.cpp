#include "browseanimalsview.h"
#include "ui_browseanimalsview.h"

BrowseAnimalsView::BrowseAnimalsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseAnimalsView)
{
    ui->setupUi(this);
    this->connect(this->ui->backButton,SIGNAL(clicked()),this,SLOT(browseBackButtonSlot()));
}

BrowseAnimalsView::~BrowseAnimalsView()
{
    delete ui;
}

QTableView* BrowseAnimalsView::getForm()
{
    return ui->tableView;
}

void BrowseAnimalsView::browseBackButtonSlot()
{
    emit browseBackButtonClicked();
}
