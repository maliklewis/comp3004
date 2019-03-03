#include "clientdetailsview.h"
#include "ui_clientdetailsview.h"

ClientDetailsView::ClientDetailsView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ClientDetailsView)
{
    ui->setupUi(this);
}

ClientDetailsView::~ClientDetailsView()
{
    delete ui;
}
