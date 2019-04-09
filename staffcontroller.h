#ifndef STAFFCONTROLLER_H
#define STAFFCONTROLLER_H
#include "mainwindow.h"
#include "stafflogin.h"
#include "staffview.h"
#include "browseanimalsview.h"
#include "addanimalview.h"
#include "databasemanager.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include "animaldetailsview.h"
#include "addclientview.h"
#include "browseclientview.h"
#include "clientdetailsview.h"
#include "algorithmcontroller.h"
#include "algorithmoutputview.h"

class StaffController : public QObject
{
    Q_OBJECT
    public:
        StaffController();
        ~StaffController();

    private:
         StaffView* staffView;
         BrowseAnimalsView* browseView;
         AddAnimalView* addAnimalView;
         AnimalDetailsView* animalDetailsView;
         ClientDetailsView* clientDetailsView;
         addclientview* addClientView;
         BrowseClientView* browseClientsView;
         AlgorithmOutputView* algorithmOutputView;


    public slots:
         void loginButtonDone();
         void browseButtonDone();
         void addAnimalButtonDone();
         void insertAnimalButtonDone();
         void browseBackButtonDone();
         void staffLogoutDone();
         void insertAnimalBackButtonDone();
         void tableItemDone();
         void addClientButtonDone();
         void insertClientButtonDone();
         void insertClientBackButtonDone();
         void browseClientsButtonDone();
         void clientTableItemDone();
         void browseClientsBackButtonDone();
         void updateButtonDone();
         void algorithmButtonDone();
         void acmBrowseClientsBackButtonDone();
         void acmClientTableItemDone();

    signals:
         //void staffLoginClicked();
         void showMain();
};

#endif // STAFFCONTROLLER_H
