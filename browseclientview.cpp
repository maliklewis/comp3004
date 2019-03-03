#include "browseclientview.h"
#include "ui_browseclientview.h"

BrowseClientView::BrowseClientView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseClientView)
{
    ui->setupUi(this);
}

BrowseClientView::~BrowseClientView()
{
    delete ui;
}

QTableView* BrowseClientView::getForm()
{
    return ui->tableView;
}
