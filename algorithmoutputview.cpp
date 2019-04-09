#include "algorithmoutputview.h"
#include "ui_algorithmoutputview.h"

AlgorithmOutputView::AlgorithmOutputView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::AlgorithmOutputView)
{
    ui->setupUi(this);
}

AlgorithmOutputView::~AlgorithmOutputView()
{
    delete ui;
}

QTableView* AlgorithmOutputView::getForm()
{
    return ui->tableView;
}

