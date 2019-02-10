#ifndef STAFFCONTROLLER_H
#define STAFFCONTROLLER_H
#include "mainwindow.h"
#include "stafflogin.h"
#include "staffview.h"
#include "databasemanager.h"
#include "qobject.h"

class StaffController : public QObject
{
    Q_OBJECT
    public:
        StaffController();
        //void launch();
        //~StaffController();
    private:
         MainWindow* mainWindow;
         StaffLogin staffLogin;
         StaffView staffview;

    public slots:
         void staffButtonDone();


};

#endif // STAFFCONTROLLER_H
