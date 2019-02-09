#include "staffview.h"
#include "ui_staffview.h"

StaffView::StaffView(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::StaffView)
{
    ui->setupUi(this);
}

StaffView::~StaffView()
{
    delete ui;
}

void StaffView::on_pushButton_clicked()
{
    this->hide();

}
