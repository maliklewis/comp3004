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
                      "costOfCare TEXT,"
                      "sheddingAmount TEXT,"
                      "aggression TEXT,"
                      "playfulness TEXT,"
                      "solitudialBehaviour TEXT,"
                      "diseaseResistance TEXT,"
                      "parasiticResistance TEXT,"
                      "goodforNOwners TEXT,"
                      "easeOfTraining TEXT,"
                      "environmentType TEXT,"
                      "winged TEXT,"
                      "vocal TEXT,"
                      "clawState TEXT)");
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
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Billy', 'Dog','Pitbull','Male',2.0,'Yes','Low','3 Years','Large','$0-$1000','Medium','High','High','Medium','High','High','No','Medium','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Bud','Dog','Chihuahua','Female',0.7,'No','Medium','4 Years','Medium','$1000-$2000','Medium','Low','High','Medium','High','Medium','No','Low','Indoor','No','High','Intact')"));

        db.exec(QString("INSERT INTO animal VALUES(Null, 'Snoopy', 'Dog','Beagle','Male',2.0,'Yes','High','7 Years','Small','$4000+','Medium','High','Low','High','High','High','Yes','Low','Indoor','No','High','Intact')"));

        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tommy', 'Dog','German Shepherd','Female',3.7,'Yes','Medium','14 Years','Small','$2000-$3000','High','Low','Low','High','High','High','Yes','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Holly', 'Dog','Poodle','Female',1.2,'Yes','Low','14 Years','Small','$1000-$2000','Low','Medium','Medium','High','High','High','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Rocky', 'Dog','Boxer','Male',0.3,'No','High','14 Years','Medium','$4000+','Low','Low','Low','Medium','High','High','No','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Donna', 'Dog','Pug','Female',2.0,'Yes','Medium','14 Years','Medium','$2000-$3000','Low','High','Low','High','Low','High','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Husky','Male',2.0,'No','Low','14 Years','Large','$0-$1000','High','Medium','Low','High','Low','High','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Diasy', 'Dog','Great Dane','Female',1.0,'Yes','High','14 Year','Small','$4000+','Low','Low','Low','High','Medium','High','Yes','Medium','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jazzy', 'Dog','Greyhound','Female',0.5,'No','Medium','14 Years','Medium','$1000-$2000','Medium','High','Low','Medium','High','Low','Yes','High','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jerry', 'Cat','Munchkin','Male',2.0,'Yes','Medium','15 Years','Small','$2000-$2000','High','Medium','Low','High','Low','Medium','Yes','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Scrappy','Cat','Persian','Male',2.0,'No','High','15 Years','Medium','4000+','High','Low','High','Low','Low','Yes','Low','Indoor','No','High','Removed')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Rondo','Cat','Bengal','Male',0.6,'Yes','Low','15 Year','Small','$0-$1000','Medium','Low','Low','High','Medium','High','Yes','Low','Outdoor','No','High','Removed')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Boots','Cat','Egyptian','Male',2.0,'Yes','High','15 Years','Medium','4000+','Medium','Medium','High','Low','High','Low','Yes','Medium','Outdoor','No','High','Removed')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luca','Cat','Himalayan','Male',1.3,'No','Medium','15 Years','Large','$1000-$2000','High','Low','Low','High','High','Medium','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tucker', 'Dog','German Shepherd','Male',2.0,'Yes','High','14 Years','Small','$2000-$3000','High','Medium','High','Low','High','Low','No','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Max', 'Dog','Greyhound','Male',4.7,'No','Low','14 Years','Medium','$0-$1000','Low','High','Medium','Low','Medium','High','Yes','Medium','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luna', 'Dog','Boxer','Female',3.2,'No','High','14 Year','Small','$4000+','Medium','Low','High','Low','High','Low','Yes','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Sadie', 'Dog','Pitbull','Male',3.3,'Yes','High','14 Years','Medium','$2000-$3000','Medium','Low','Low','High','High','Medium','Yes','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Dog','Pug','Female',2.5,'No','Low','14 Years','Small','$0-$1000','Low','Medium','Low','Low','Medium','High','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tucker', 'Dog','Beagle','Male',2.0,'Yes','Medium','14 Years','Medium','$1000-$2000','Low','High','Low','High','Medium','Low','Yes','High','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Max', 'Dog','Chihuahua','Male',3.7,'Yes','Low','14 Years','Small','$0-$1000','Medium','Low','High','Low','High','Medium','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Claire', 'Dog','Great Dane','Female',2.3,'No','Medium','14 Years','Large','$1000-$2000','Medium','High','Low','High','Medium','Low','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Sadie', 'Bird','Dove','Male',3.3,'No','High','20 Years','Small','$2000-$3000','Low','Low','Medium','Medium','High','Low','Yes','Medium','Outdoor','Yes','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jolly', 'Bird','Canary','Female',1.5,'No','High','20 Years','Large','$4000+','Medium','High','Low','High','Low','High','Yes','Low','Outdoor','Yes','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Bird','Lovebird','Female',3.5,'Yes','Low','20 Years','Medium','$0-$1000','Medium','Medium','High','Low','High','Medium','Yes','High','Indoor','Yes','High','Intact')"));


        //staff members
        db.exec(QString("INSERT INTO staff VALUES(Null, 'John Smith', 'jsmith@gmail.com')"));

        //client members
        db.exec(QString("INSERT INTO client VALUES(Null,'Jane Doe','(613)-700-1137','j.doe@gmail.com',26, 0, 0, 'FALSE', 'A', '0', 'TRUE', 240000, 'Townhouse')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Johnny Cage','(613)-756-1237','cage2434@gmail.com',30, 1, 14, 'FALSE', 'B', '0', 'FALSE', 45000, 'Apartment')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Patrick Tahar','(343)-721-5431','taharpatrick40@hotmail.com',40, 2, 23, 'TRUE', 'C', '1', 'FALSE', 35000, 'Detached')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Arnold Volkswagen','(613)-884-2201','arniev24@yahoo.co.uk',45, 3, 20, 'FALSE', 'A', '1', 'TRUE', 150000, 'Semi-Detached')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Cardi Blackie','(514)-834-3345','cblackie1@gmail.com',23, 0, 0, 'FALSE', 'C', '0', 'FALSE', 30000, 'Apartment')"));

     }
}





