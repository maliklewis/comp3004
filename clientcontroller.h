#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H
#include "mainwindow.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include "databasemanager.h"
#include "clientlogin.h"
#include "clientview.h"
#include "browseanimalsview.h"
#include "animaldetailsview.h"

class ClientController : public QObject
{
    Q_OBJECT
    public:
        ClientController();
        ~ClientController();
    private:
         MainWindow* mainWindow;
         ClientLogin* clientLogin;
         ClientView* clientView;
         BrowseAnimalsView* browseView;
         AnimalDetailsView* animalDetailsView;
    public slots:
         void clientLoginButtonDone();
         void browseButtonDone();
         void tableItemDone();

};

#endif // CLIENTCONTROLLER_H
