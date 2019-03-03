#ifndef CLIENTCONTROLLER_H
#define CLIENTCONTROLLER_H
#include "mainwindow.h"
#include <QtSql>
#include <QDebug>
#include <QMessageBox>
#include "databasemanager.h"
#include "clientlogin.h"
#include "staffcontroller.h"


class ClientController : public QObject
{
    Q_OBJECT
    public:
        ClientController();
        ~ClientController();
    private:
         MainWindow* mainWindow;
         ClientLogin* clientLogin;
         StaffController* staffController;
    private slots:
         void clientButtonDone();
};

#endif // CLIENTCONTROLLER_H
