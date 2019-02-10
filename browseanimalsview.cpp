#include "browseanimalsview.h"
#include "ui_browseanimalsview.h"

BrowseAnimalsView::BrowseAnimalsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseAnimalsView)
{
    ui->setupUi(this);
}

BrowseAnimalsView::~BrowseAnimalsView()
{
    delete ui;
}

QTableView* BrowseAnimalsView::getForm()
{
    return ui->tableView;
}
