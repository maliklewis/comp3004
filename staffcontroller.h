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

class StaffController : public QObject
{
    Q_OBJECT
    public:
        StaffController();
        //void launch();
        ~StaffController();
    private:
         MainWindow* mainWindow;
         StaffLogin* staffLogin;
         StaffView* staffView;
         BrowseAnimalsView* browseView;
         AddAnimalView* addAnimalView;
         AnimalDetailsView* animalDetailsView;

    public slots:
         void staffButtonDone();
         void loginButtonDone();
         void browseButtonDone();
         void addAnimalButtonDone();
         void insertAnimalButtonDone();
         void browseBackButtonDone();
         void staffLogoutDone();
         void insertAnimalBackButtonDone();
         void tableItemDone();


};

#endif // STAFFCONTROLLER_H
