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
#include "editclientdetailsview.h"
#include "clientpreferencesview.h"

class ClientController : public QObject
{
    Q_OBJECT
    public:
        ClientController();
        ~ClientController();
        QString username;
    private:
         MainWindow* mainWindow;
         ClientLogin* clientLogin;
         ClientView* clientView;
         BrowseAnimalsView* browseView;
         AnimalDetailsView* animalDetailsView;
         EditClientDetailsView* editDetailsView;
         ClientPreferencesView* clientPrefView;
    public slots:
         void clientLoginButtonDone();
         void browseButtonDone();
         void tableItemDone();
         void browseBackButtonDone();
         void clientLogoutDone();
         void editProfileDone();
         void editClientBackButtonDone();
         void editClientAddButtonDone();
         void editClientPrefButtonDone();
         void clientPrefSaveButtonDone();
    signals:
         void showMain();

};

#endif // CLIENTCONTROLLER_H
