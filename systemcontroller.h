#ifndef SYSTEMCONTROLLER_H
#define SYSTEMCONTROLLER_H
#include "mainwindow.h"
#include "databasemanager.h"
#include "stafflogin.h"
#include "staffview.h"
#include "staffcontroller.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>


class SystemController : public QObject
{
    Q_OBJECT
    public:
        SystemController();
        ~SystemController();
    private:
        StaffController* staffControl;
        MainWindow* mainWindow;
        StaffLogin* staffLogin;
        StaffView* staffView;
    public slots:
         void staffButtonDone();
         void staffLoginButtonDone();
         void loggedOutDone();
    signals:
         void startStaffController();


};

#endif // SYSTEMCONTROLLER_H
