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
    //db.setHostName("QDir::currentPath()");
    db.setDatabaseName(QDir::currentPath() + "/tables.db");
    qDebug()<<QDir::currentPath();

    bool db_open = db.open();
    if(db_open){
        qDebug()<<"connected";
    }else{
        qDebug()<<"not connected";
    }

    //if the database doesnt exist, create it
        //then populate it with default values

    dbBuild();
    dbPopulate();

    return db_open;
}

bool databasemanager::dbBuild(){
    //Create required tables for the database
    databasemanager::makeAnimalTable();
    databasemanager::makeStaffTable();
    return true;
}

bool databasemanager::makeAnimalTable(){
    bool ret = false;
    if(db.isOpen()){
        QSqlQuery qry;
        ret = qry.exec("CREATE TABLE IF NOT EXISTS animal"
                      "(animal_id INTEGER PRIMARY KEY, "
                      "name TEXT,"
                      "type TEXT,"
                      "breed TEXT)");
        if(!ret)
            qDebug()<<"Animal Table not created";
    }
    return ret;

}

bool databasemanager::makeStaffTable(){
    bool ret = false;
    if(db.isOpen()){
        QSqlQuery qry;
        ret = qry.exec("CREATE TABLE IF NOT EXISTS staff"
                      "(staff_id INTEGER PRIMARY KEY, "
                      "name TEXT,"
                      "email TEXT NOT NULL UNIQUE)");
        if(!ret)
            qDebug()<<"Staff Table not created";
    }
    return ret;
}


void databasemanager::dbPopulate(){
     QSqlQuery query;
     query.exec("SELECT * FROM animal limit 1");

     if (!query.next()) {
        qDebug()<<"running";
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Pitbull')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Chihuahua')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Beagle')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','German Shepherd')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Poodle')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Boxer')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Pug')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Husky')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Great Dane')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Greyhound')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Cat','Munchkin')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Cat','Persian')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Cat','Bengal')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Cat','Egyptian')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Cat','Himalayan')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Bird','Parrot')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Bird','Cockatoo')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Bird','Lovebird')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Bird','Canary')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Bird','Dove')"));

        db.exec(QString("INSERT INTO staff VALUES(Null, 'John Smith', 'jsmith@gmail.com')"));
     }
}





