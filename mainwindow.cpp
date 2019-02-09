#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::on_staffButton_clicked()
{
    this->hide();
    StaffLogin staffLogin;
    staffLogin.setModal(true);
    staffLogin.exec();
}
