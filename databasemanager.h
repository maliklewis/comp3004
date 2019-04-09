#ifndef DATABASEMANAGER_H
#define DATABASEMANAGER_H
#include <QObject>
#include <QSqlDatabase>
#include "animalfactory.h"
#include "animal.h"
#include <QVector>
#include <QMapIterator>

class databasemanager : public QObject
{
    Q_OBJECT
public:
    static databasemanager* getInstance();
    QVector<QMap<QString, QString>> animalList;
    QVector<QMap<QString, QString>> clientList;
    int benchMark =0;
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
    bool editClientPrefInfo(QVector<QString>);

    QString highGoodConversion(QString);
    QString lowGoodConversion(QString);
    QString costConversion(QString);
    QString clawStateConversion(QString);
    QString animalAgeConversion(double);
    QString clientAgeConversion(int);
    QString yesOrNoConversion(QString);
    void createAnimalObjects();
    QString houseSizeConversion(QString);
    QString employmentConversion(QString);
    QString styleConversion(QString);
    QString incomeConversion(int);
    void createClientList();
    QString ageRangeConversion(QString);
    QString kidFriendlyConversion(QString, QString);
    QString immuneConversion(QString, QString);
    QString dependableConversion(QString, QString, QString);
    //void initMatches();



private:
    QSqlDatabase db;
    static databasemanager* instance;
    AnimalFactory* factory;
    databasemanager();

signals:

public slots:
};

#endif // DATABASEMANAGER_H
