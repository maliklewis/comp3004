#include "databasemanager.h"
#include <QtSql>
#include <QDebug>


databasemanager::databasemanager(QObject *parent) : QObject(parent)
{
}

bool databasemanager::dbOpen(){

    //sqlite driver
    db = QSqlDatabase::addDatabase("QSQLITE");
    //db.setHostName("QDir::currentPath()");
    db.setDatabaseName(QDir::currentPath() + "/tables.db");
    qDebug()<<QDir::currentPath();

    bool db_open = db.open();
    if(db_open){
        qDebug()<<"Database connected";
    }else{
        qDebug()<<"Database not connected";
    }

    //if the database doesnt exist, create it
        //then populate it with default values

    dbBuild();
    dbPopulate();

    return db_open;
}

bool databasemanager::dbBuild(){
    //Create required tables for the database
    makeAnimalTable();
    makeStaffTable();
    makeClientTable();
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
                      "breed TEXT,"
                      "gender TEXT,"
                      "age DOUBLE,"
                      "houstrained TEXT,"
                      "specialNeeds TEXT,"
                      "lifeSpan TEXT,"
                      "size TEXT,"
                      "costOfCare INT,"
                      "sheddingAmount INT,"
                      "aggression INT,"
                      "playfulness TEXT,"
                      "solitudialBehaviour TEXT,"
                      "deseaseResistance TEXT,"
                      "parasiticResistance TEXT,"
                      "goodforNOwners TEXT,"
                      "easeOfTraining TEXT,"
                      "trainingType TEXT)");
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

bool databasemanager::makeClientTable(){
    bool ret = false;
    if(db.isOpen()){
        QSqlQuery qry;
        ret = qry.exec("CREATE TABLE IF NOT EXISTS client"
                      "(client_id INTEGER PRIMARY KEY, "
                      "name TEXT,"
                      "number TEXT,"
                      "email TEXT NOT NULL UNIQUE,"
                      "age INT,"
                      "numberOfChildren INT,"
                      "ageOfChildren INT,"
                      "otherAnimals BOOL,"
                      "employmentType TEXT,"
                      "maritalStatus INT,"
                      "employmentStatus BOOL,"
                      "income INT,"
                      "architectureStyle TEXT)");
        if(!ret)
            qDebug()<<"Client Table not created";
    }
    return ret;
}


void databasemanager::dbPopulate(){
     QSqlQuery query;
     query.exec("SELECT * FROM animal limit 1");

     if (!query.next()) {
        qDebug()<<"running";

        //animals
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Billy', 'Dog','Pitbull','Male',2.0,'Yes','Mild','3 Years','Small','Average',24,12,'Low','High','High','High','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Bud','Dog','Chihuahua','Female',0.7)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Snoopy', 'Dog','Beagle','Male',2.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tommy', 'Dog','German Shepherd','Female',3.7)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Holly', 'Dog','Poodle','Female',1.2)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Rocky', 'Dog','Boxer','Male',0.3)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Donna', 'Dog','Pug','Female',2.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Husky','Male',2.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Diasy', 'Dog','Great Dane','Female',1.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jazzy', 'Dog','Greyhound','Female',0.5)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jerry', 'Cat','Munchkin','Male',2.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Scrappy','Cat','Persian','Male',2.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Rondo','Cat','Bengal','Male',0.6)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Boots','Cat','Egyptian','Male',2.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luca','Cat','Himalayan','Male',1.3)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tucker', 'Dog','Coundhound','Male',2.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Max', 'Dog','Hunting Dog','Male',4.7)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luna', 'Dog','Toy Dog','Female',3.2)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Sadie', 'Dog','Setter','Male',3.3)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Dog','Spaniel','Female',2.5)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tucker', 'Dog','Coundhound','Male',2.0)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Max', 'Dog','Bull Terrier','Male',3.7)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luna', 'Dog','Doberman','Female',2.3)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Sadie', 'Dog','Cane Corso','Male',3.3)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Dog','Bloodhound','Female',1.5)"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Dog','Toy Poodle','Female',3.5)"));

        //staff members
        db.exec(QString("INSERT INTO staff VALUES(Null, 'John Smith', 'jsmith@gmail.com')"));

        //client members
        db.exec(QString("INSERT INTO client VALUES(Null,'Jane Doe','(613)-700-1137','j.doe@gmail.com',26, 0, 0, 'FALSE', 'A', '0', 'TRUE', 24000, 'townhouse')"));

     }
}





