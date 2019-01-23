#include "databasemanager.h"
#include <QtSql>
#include <QDebug>


databasemanager::databasemanager(QObject *parent) : QObject(parent)
{
}

bool databasemanager::dbOpen(){
    bool db_exists = true;

    //sqlite driver
    db = QSqlDatabase::addDatabase("QSQLITE");

    //get the home path on users pc for database
    QString path(QDir::home().path());
    path.append(QDir::separator()).append("tables.db.sqlite");
    path = QDir::toNativeSeparators(path);

    //check if the file exists
    QFile fOut(path);

    //if the database file doesnt exist
    if(!fOut(path).exists()){
        db_exists = false;
    }

    db.setDatabaseName(path);

    bool db_open = db.open();

    //if the database doesnt exist, create it
        //then populate it with default values
    if(!db_exists){

        dbBuild();
        dbPopulate();
    }

    return db_open;
}

bool databasemanager::dbBuild(){
    //Create required tables for the database
    databasemanager::makeAnimalTable();

    return true;
}

bool databasemanager::makeAnimalTable(){
    bool ret = false;
    if(db.isOpen()){
        QSqlQuery qry;
        ret =qry.exec("CREATE TABLE IF NOT EXISTS animal"
                      "animal_id INTEGER PRIMARY KEY, "
                      "name TEXT,"
                      "type TEXT,"
                      "breed TEXT)");
        if(!ret)
            qdebug()<<"Table not created";


    }

}




