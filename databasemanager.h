#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QObject>
#include <QSqlDatabase>
#include "animalfactory.h"
#include "animal.h"
#include <QList>

class databasemanager : public QObject
{
    Q_OBJECT
public:
    static databasemanager* getInstance();
    QList<Animal*> animals;
    //explicit databasemanager(QObject *parent = 0);
    bool dbOpen();
    bool dbBuild();
    bool dbClose();
    void dbPopulate();

    bool makeAnimalTable();
    bool makeStaffTable();
    bool makeClientTable();
    QVector<QString> editClientGetinfo(QString);
    bool editClientaddInfo(QVector<QString>);
    QVector<QString> getAnimalinfo(QString);
    QVector<QString> getClientinfo(QString);
    QSqlQuery browseAnimalsQuery();
    QSqlQuery browseClientsQuery();
    bool insertAnimalquery(QVector<QString>);
    bool insertClientquery(QVector<QString>);
    bool updateAnimalquery(QVector<QString>);

    int highGoodConversion(QString);
    int lowGoodConversion(QString);
    int costConversion(QString);
    int clawStateConversion(QString);
    int ageConversion(double);
    int yesOrNoConversion(QString);
    //int wingedConversion(QString);
    void createAnimalObjects();


private:
    QSqlDatabase db;
    static databasemanager* instance;
    AnimalFactory* factory;
    databasemanager();

signals:

public slots:
};

#endif // DATABASEMANAGER_H
