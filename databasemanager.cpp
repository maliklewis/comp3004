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
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Billy', 'Dog','Pitbull','Male',2.0,'Yes','Mild','3 Years','Large',68,66,33,'High','Medium,','Medium','High','Yes','Medium','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Bud','Dog','Chihuahua','Female',0.7,'No','Mild','4 Years','Medium',99,33,77,'Low','High','Medium','High','No','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Snoopy', 'Dog','Beagle','Male',2.0,'Yes','Mild','7 Years','Small',54,64,52,'Low','High','High','High','Yes','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tommy', 'Dog','German Shepherd','Female',3.7,'Yes','Mild','2 Years','Small',65,98,36,'Low','High','High','High','Yes','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Holly', 'Dog','Poodle','Female',1.2,'Yes','Mild','5 Years','Small',44,85,53,'Medium','High','High','High','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Rocky', 'Dog','Boxer','Male',0.3,'No','Mild','9 Years','Medium',96,24,78,'Low','Medium','High','High','No','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Donna', 'Dog','Pug','Female',2.0,'Yes','Mild','2 Years','Medium',34,33,12,'Low','High','Low','High','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Ralph', 'Dog','Husky','Male',2.0,'No','Mild','6 Years','Large',80,24,53,'Low','High','Low','High','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Diasy', 'Dog','Great Dane','Female',1.0,'Yes','Mild','1 Year','Small',39,24,33,'Low','High','Medium','High','Yes','Medium','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jazzy', 'Dog','Greyhound','Female',0.5,'No','Mild','6 Years','Medium',55,55,21,'Low','Medium','High','Low','Yes','High','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jerry', 'Cat','Munchkin','Male',2.0,'Yes','Mild','7 Years','Small',92,39,43,'Low','High','Low','Medium','Yes','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Scrappy','Cat','Persian','Male',2.0,'No','Mild','4 Years','Medium',83,16,32,'Low','High','Low','Low','Yes','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Rondo','Cat','Bengal','Male',0.6,'Yes','Mild','1 Year','Small''49,34,62,'Low','High','Medium','High','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Boots','Cat','Egyptian','Male',2.0,'Yes','Mild','9 Years','Medium',74,19,29,'High','Low','High','Low','Yes','Medium','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luca','Cat','Himalayan','Male',1.3,'No','Mild','3 Years','Large',99,77,21,'Low','High','High','Medium','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tucker', 'Dog','Coundhound','Male',2.0,'Yes','Mild','5 Years','Small',88,36,34,'Low','High','Low','High','No','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Max', 'Dog','Hunting Dog','Male',4.7,'No','Mild','2 Years','Medium',39,44,23,'Low','Medium','High','Low','Yes','Medium','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luna', 'Dog','Toy Dog','Female',3.2,'No','Mild','1 Year','Small',65,33,12,'Low','High','Low','High','Yes','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Sadie', 'Dog','Setter','Male',3.3,'Yes','Mild','8 Years','Medium',78,61,33,'Low','High','High','Medium','Yes','Low','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Dog','Spaniel','Female',2.5,'No','Mild','4 Years','Small',74,25,67,'Low','Low','Medium','High','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tucker', 'Dog','Coundhound','Male',2.0,'Yes','Mild','7 Years','Medium',57,4,62,'Low','High','Medium','Low','Yes','High','Indoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Max', 'Dog','Bull Terrier','Male',3.7,'Yes','Mild','2 Years','Small',63,45,9,'High','Low','High','Medium','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luna', 'Dog','Doberman','Female',2.3,'No','Mild','6 Years','Large',41,76,5,'Low','High','Medium','Low','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Sadie', 'Dog','Cane Corso','Male',3.3,'No','Mild','2 Years','Small',77,98,36,'Medium','Medium','High','Low','Yes','Medium','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Dog','Bloodhound','Female',1.5,'No','Mild','7 Years','Large',62,43,47,'Low','High','Low','High','Yes','Low','Outdoor')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Dog','Toy Poodle','Female',3.5,'Yes','Mild','9 Years','Medium',95,24,54,'High','Low','High','Medium','Yes','High','Indoor')"));

        //staff members
        db.exec(QString("INSERT INTO staff VALUES(Null, 'John Smith', 'jsmith@gmail.com')"));

        //client members
        db.exec(QString("INSERT INTO client VALUES(Null,'Jane Doe','(613)-700-1137','j.doe@gmail.com',26, 0, 0, 'FALSE', 'A', '0', 'TRUE', 240000, 'townhouse')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Johnny Cage','(613)-756-1237','cage2434@gmail.com',30, 1, 14, 'FALSE', 'B', '0', 'FALSE', 45000, 'apartment')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Patrick Tahar','(343)-721-5431','taharpatrick40@hotmail.com',40, 2, 23, 'TRUE', 'C', '1', 'FALSE', 35000, 'detached')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Arnold Volkswagen','(613)-884-2201','arniev24@yahoo.co.uk',45, 3, 20, 'FALSE', 'A', '1', 'TRUE', 150000, 'semi-detached')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Cardi Blackie','(514)-834-3345','cblackie1@gmail.com',23, 0, 0, 'FALSE', 'C', '0', 'FALSE', 30000, 'apartment')"));

     }
}





