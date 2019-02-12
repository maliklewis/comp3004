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

//getter function for retrieving the tableview variable
QTableView* BrowseAnimalsView::getForm()
{
    return ui->tableView;
}

void BrowseAnimalsView::browseBackButtonSlot()
{
    emit browseBackButtonClicked();
}

void BrowseAnimalsView::on_tableView_doubleClicked(const QModelIndex &index)
{
    tableRow = index.row() + 1;
    tableRowString = QString::number(tableRow);
    emit tableItemClicked();
}
