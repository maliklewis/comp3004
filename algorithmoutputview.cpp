#include "algorithmoutputview.h"
#include "ui_algorithmoutputview.h"

AlgorithmOutputView::AlgorithmOutputView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlgorithmOutputView)
{
    ui->setupUi(this);
    this->connect(this->ui->backButton,SIGNAL(clicked()),this,SLOT(browseBackButtonSlot()));
}

AlgorithmOutputView::~AlgorithmOutputView()
{
    delete ui;
}

QTableView* AlgorithmOutputView::getForm()
{
    return ui->tableView;
}

void AlgorithmOutputView::browseBackButtonSlot()
{
    emit browseClientsBackButtonClicked();
}

void AlgorithmOutputView::on_tableView_doubleClicked(const QModelIndex &index)
{
    acmTableRow = index.row() + 1;
    acmTableRowString = QString::number(acmTableRow);
    emit tableItemClicked();
}

