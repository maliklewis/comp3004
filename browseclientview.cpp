#include "browseclientview.h"
#include "ui_browseclientview.h"

BrowseClientView::BrowseClientView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::BrowseClientView)
{
    ui->setupUi(this);
    this->connect(this->ui->backButton,SIGNAL(clicked()),this,SLOT(browseClientsBackButtonSlot()));
}

BrowseClientView::~BrowseClientView()
{
    delete ui;
}

QTableView* BrowseClientView::getForm()
{
    return ui->tableView;
}

void BrowseClientView::browseClientsBackButtonSlot()
{
    emit browseClientsBackButtonClicked();
}

void BrowseClientView::on_tableView_doubleClicked(const QModelIndex &index)
{
    clientTableRow = index.row() +1;
    clientTableRowString = QString::number(clientTableRow);
    emit clientTableItemClicked();
}
