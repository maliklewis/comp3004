#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H
#include "mainwindow.h"
#include "databasemanager.h"
#include "stafflogin.h"
#include "clientlogin.h"
#include "staffview.h"
#include "staffcontroller.h"
#include "clientcontroller.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>


class SystemController : public QObject
{
    Q_OBJECT
    public:
        //SystemController();
        ~SystemController();
        static SystemController* getInstance();
    private:
        StaffController* staffControl;
        ClientController* clientControl;
        MainWindow* mainWindow;
        StaffLogin* staffLogin;
        StaffView* staffView;
        ClientLogin* clientLogin;

        //Instance will be stored here
        static SystemController* instance;

        //private constructor to prevent instancing
        SystemController();
    public slots:
         void staffButtonDone();
         void clientButtonDone();
         void staffLoginButtonDone();
         void clientLoginButtonDone();
         void loggedOutDone();
         void staffLoginBackButtonDone();
         void clientLoginBackButtonDone();
    signals:
         void startStaffController();
};

#endif // SYSTEMCONTROLLER_H
