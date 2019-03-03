#include "mainwindow.h"
#include "ui_mainwindow.h"


MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    this->connect(this->ui->staffButton,SIGNAL(clicked()),this,SLOT(staffButtonSlot()));
    this->connect(this->ui->clientButton,SIGNAL(clicked()),this,SLOT(clientButtonSlot()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::staffButtonSlot()
{
    emit staffButtonClicked();
}

void MainWindow::clientButtonSlot()
{
    emit clientButtonClicked();
}


