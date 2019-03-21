#include "databasemanager.h"
#include <QtSql>
#include <QDebug>

databasemanager::databasemanager(){}

databasemanager* databasemanager::instance = 0;

databasemanager* databasemanager::getInstance()
{
    if (instance == 0)
    {
        instance = new databasemanager();
    }
    return instance;
}

bool databasemanager::dbOpen(){

    //sqlite driver
    db = QSqlDatabase::addDatabase("QSQLITE");
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
                      "name TEXT UNIQUE,"
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
                      "(staff_id INTEGER, "
                      "name TEXT,"
                      "email TEXT NOT NULL PRIMARY KEY)");
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
                      "(client_id INTEGER, "
                      "name TEXT,"
                      "number TEXT,"
                      "email TEXT NOT NULL PRIMARY KEY,"
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
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Daisy', 'Dog','Great Dane','Female',1.0,'Yes','High','14 Year','Small','$4000+','Low','Low','Low','High','Medium','High','Yes','Medium','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jazzy', 'Dog','Greyhound','Female',0.5,'No','Medium','14 Years','Medium','$1000-$2000','Medium','High','Low','Medium','High','Low','Yes','High','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jerry', 'Cat','Munchkin','Male',2.0,'Yes','Medium','15 Years','Small','$2000-$2000','High','Medium','Low','High','Low','Medium','Yes','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Scrappy','Cat','Persian','Male',2.0,'No','High','15 Years','Medium','4000+','High','Low','High','Low','Low','Yes','Low','Indoor','No','High','Removed')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Rondo','Cat','Bengal','Male',0.6,'Yes','Low','15 Year','Small','$0-$1000','Medium','Low','Low','High','Medium','High','Yes','Low','Outdoor','No','High','Removed')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Boots','Cat','Egyptian','Male',2.0,'Yes','High','15 Years','Medium','4000+','Medium','Medium','High','Low','High','Low','Yes','Medium','Outdoor','No','High','Removed')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luca','Cat','Himalayan','Male',1.3,'No','Medium','15 Years','Large','$1000-$2000','High','Low','Low','High','High','Medium','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tucker', 'Dog','German Shepherd','Male',2.0,'Yes','High','14 Years','Small','$2000-$3000','High','Medium','High','Low','High','Low','No','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Max', 'Dog','Greyhound','Male',4.7,'No','Low','14 Years','Medium','$0-$1000','Low','High','Medium','Low','Medium','High','Yes','Medium','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Luna', 'Dog','Boxer','Female',3.2,'No','High','14 Year','Small','$4000+','Medium','Low','High','Low','High','Low','Yes','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Sandy', 'Dog','Pitbull','Male',3.3,'Yes','High','14 Years','Medium','$2000-$3000','Medium','Low','Low','High','High','Medium','Yes','Low','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Moly', 'Dog','Pug','Female',2.5,'No','Low','14 Years','Small','$0-$1000','Low','Medium','Low','Low','Medium','High','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Tucker', 'Dog','Beagle','Male',2.0,'Yes','Medium','14 Years','Medium','$1000-$2000','Low','High','Low','High','Medium','Low','Yes','High','Indoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Max', 'Dog','Chihuahua','Male',3.7,'Yes','Low','14 Years','Small','$0-$1000','Medium','Low','High','Low','High','Medium','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Claire', 'Dog','Great Dane','Female',2.3,'No','Medium','14 Years','Large','$1000-$2000','Medium','High','Low','High','Medium','Low','Yes','Low','Outdoor','No','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Sadie', 'Bird','Dove','Male',3.3,'No','High','20 Years','Small','$2000-$3000','Low','Low','Medium','Medium','High','Low','Yes','Medium','Outdoor','Yes','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Jolly', 'Bird','Canary','Female',1.5,'No','High','20 Years','Large','$4000+','Medium','High','Low','High','Low','High','Yes','Low','Outdoor','Yes','High','Intact')"));
        db.exec(QString("INSERT INTO animal VALUES(Null, 'Molly', 'Bird','Lovebird','Female',3.5,'Yes','Low','20 Years','Medium','$0-$1000','Medium','Medium','High','Low','High','Medium','Yes','High','Indoor','Yes','High','Intact')"));


        //staff members
        db.exec(QString("INSERT INTO staff VALUES(Null, 'John Smith', 'jsmith@gmail.com')"));
        db.exec(QString("INSERT INTO staff VALUES(Null, 'John Doe', 'jdoe@gmail.com')"));

        //client members
        db.exec(QString("INSERT INTO client VALUES(Null,'Jane Doe','(613)-700-1137','j.doe@gmail.com',26, 0, 0, 'FALSE', 'A', '0', 'TRUE', 240000, 'Townhouse')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Johnny Cage','(613)-756-1237','cage2434@gmail.com',30, 1, 14, 'FALSE', 'B', '0', 'FALSE', 45000, 'Apartment')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Patrick Tahar','(343)-721-5431','taharpatrick40@hotmail.com',40, 2, 23, 'TRUE', 'C', '1', 'FALSE', 35000, 'Detached')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Arnold Volkswagen','(613)-884-2201','arniev24@yahoo.co.uk',45, 3, 20, 'FALSE', 'A', '1', 'TRUE', 150000, 'Semi-Detached')"));
        db.exec(QString("INSERT INTO client VALUES(Null,'Cardi Blackie','(514)-834-3345','cblackie1@gmail.com',23, 0, 0, 'FALSE', 'C', '0', 'FALSE', 30000, 'Apartment')"));

     }
}

QVector<QString> databasemanager::editClientGetinfo(QString name)
{
    QSqlQuery qry;
    qry.prepare("SELECT number, email from client WHERE name = '"+name+"'");
    qry.exec();
    qry.next();
    QVector<QString> vector;
    vector.append(qry.value(0).toString());
    vector.append(qry.value(1).toString());

    return vector;
}

bool databasemanager::editClientaddInfo(QVector<QString> v)
{
    QSqlQuery qry;
    bool ret = false;
    qry.prepare("UPDATE client SET age ='"+v.at(3)+"', numberOfChildren ='"+v.at(4)+"', ageOfChildren ='"+v.at(5)+"',otherAnimals = '"+v.at(6)+"',employmentType = '"+v.at(7)+"',maritalStatus ='"+v.at(8)+"',employmentStatus = '"+v.at(9)+"',income = '"+v.at(10)+"',architectureStyle = '"+v.at(11)+"' WHERE name = '"+v.at(0)+"'");
    ret = qry.exec();
    return ret;
}

bool databasemanager::insertClientquery(QVector<QString> v)
{
    QSqlQuery qry;
    bool ret = false;

    qry.prepare("INSERT INTO client VALUES (Null,'"+v.at(0)+"',"
                                                         "'"+v.at(1)+"',"
                                                         "'"+v.at(2)+"',"
                                                         "Null,Null,Null,Null,Null,Null,Null,Null,Null)");
            ret = qry.exec();
            return ret;
}

bool databasemanager::insertAnimalquery(QVector<QString> v)
{
    QSqlQuery qry;
    bool ret = false;

    qry.prepare("INSERT INTO animal VALUES (Null,'"+v.at(0)+"',"
                                                 "'"+v.at(1)+"',"
                                                 "'"+v.at(2)+"',"
                                                 "'"+v.at(3)+"',"
                                                 "'"+v.at(4)+"',"
                                                 "'"+v.at(5)+"',"
                                                 "'"+v.at(6)+"',"
                                                 "'"+v.at(7)+"',"
                                                 "'"+v.at(8)+"',"
                                                 "'"+v.at(9)+"',"
                                                 "'"+v.at(10)+"',"
                                                 "'"+v.at(11)+"',"
                                                 "'"+v.at(12)+"',"
                                                 "'"+v.at(13)+"',"
                                                 "'"+v.at(14)+"',"
                                                 "'"+v.at(15)+"',"
                                                 "'"+v.at(16)+"',"
                                                 "'"+v.at(17)+"',"
                                                 "'"+v.at(18)+"',"
                                                 "'"+v.at(19)+"',"
                                                 "'"+v.at(20)+"',"
                                                 "'"+v.at(21)+"')");
            ret = qry.exec();


            return ret;
}
QVector<QString> databasemanager::getClientinfo(QString client_id)
{
    QSqlQuery qry;
    QVector<QString> vector;

    qry.prepare("SELECT name,number,email,age,numberOfChildren,ageOfChildren,otherAnimals,employmentType,maritalStatus,employmentStatus,income,architectureStyle from client WHERE client_id = '"+client_id+"'");

    qry.exec();
    qry.next();
    vector.append(qry.value(0).toString());
    vector.append(qry.value(1).toString());
    vector.append(qry.value(2).toString());
    vector.append(qry.value(3).toString());
    vector.append(qry.value(4).toString());
    vector.append(qry.value(5).toString());
    vector.append(qry.value(6).toString());
    vector.append(qry.value(7).toString());
    vector.append(qry.value(8).toString());
    vector.append(qry.value(9).toString());
    vector.append(qry.value(10).toString());
    vector.append(qry.value(11).toString());

    return vector;

}

QVector<QString> databasemanager::getAnimalinfo(QString animal_id)
{
    QSqlQuery qry;
    QVector<QString> vector;
    qry.prepare("SELECT name,type,breed,gender,age,houstrained,specialNeeds,lifeSpan,size,playfulness,winged,costOfCare,sheddingAmount,"
                "aggression,solitudialBehaviour,diseaseResistance,parasiticResistance,goodforNOwners,"
                "easeOfTraining,environmentType,vocal,clawState from animal WHERE animal_id = '"+animal_id+"'");
    qry.exec();
    qry.next();
    
    vector.append(qry.value(0).toString());
    vector.append(qry.value(1).toString());
    vector.append(qry.value(2).toString());
    vector.append(qry.value(3).toString());
    vector.append(qry.value(4).toString());
    vector.append(qry.value(5).toString());
    vector.append(qry.value(6).toString());
    vector.append(qry.value(7).toString());
    vector.append(qry.value(8).toString());
    vector.append(qry.value(9).toString());
    vector.append(qry.value(10).toString());
    vector.append(qry.value(11).toString());
    vector.append(qry.value(12).toString());
    vector.append(qry.value(13).toString());
    vector.append(qry.value(14).toString());
    vector.append(qry.value(15).toString());
    vector.append(qry.value(16).toString());
    vector.append(qry.value(17).toString());
    vector.append(qry.value(18).toString());
    vector.append(qry.value(19).toString());
    vector.append(qry.value(20).toString());
    vector.append(qry.value(21).toString());

    return vector;
}

bool databasemanager::updateAnimalquery(QVector<QString> v)
{
    QSqlQuery qry;
    bool ret = false;

    qry.prepare("UPDATE animal SET houstrained = '"+v.at(0)+"', specialNeeds = '"+v.at(1)+"', lifespan = '"+v.at(2)+"', size = '"+v.at(3)+"', costOfCare = '"+v.at(4)+"', sheddingAmount = '"+v.at(5)+"', aggression = '"+v.at(6)+"', playfulness = '"+v.at(7)+"', solitudialBehaviour = '"+v.at(8)+"', diseaseResistance = '"+v.at(9)+"', parasiticResistance = '"+v.at(10)+"', goodforNOwners = '"+v.at(11)+"', easeOfTraining = '"+v.at(12)+"', environmentType = '"+v.at(13)+"', winged = '"+v.at(14)+"', vocal = '"+v.at(15)+"', clawState = '"+v.at(16)+"' WHERE name = '"+v.at(17)+"'");
    ret = qry.exec();
    return ret;
}

QSqlQuery databasemanager::browseAnimalsQuery(){
    QSqlQuery qry;
    qry.prepare("Select name, type, breed from animal");
    qry.exec();
    return qry;
}

QSqlQuery databasemanager::browseClientsQuery(){
    QSqlQuery qry;
    qry.prepare("Select name, number, email from client");
    qry.exec();
    return qry;
}

//converter function for string to positive int
int databasemanager::highGoodConversion(QString value)
{
    int ret = 0;
    if (value == "High"){
        ret = 3;
    }
    else if (value == "Medium"){
        ret = 2;
    }
    else if (value == "Low"){
        ret = 1;
    }
    else {
       ret = 0;
    }
    return ret;
}

int databasemanager::yesOrNoConversion(QString value)
{
    int ret = 0;
    if (value == "Yes"){
        ret = 1;
    }
    else {
        ret = 0;
    }
    return ret;
}

int databasemanager::lowGoodConversion(QString value)
{
    int ret = 0;
    if (value == "High"){
        ret = 1;
    }
    else if (value == "Medium"){
        ret = 2;
    }
    else if (value == "Low"){
        ret = 3;
    }
    else {
       ret = 0;
    }
    return ret;
}

int databasemanager::costConversion(QString value)
{
    int ret = 0;
    if (value == "$0-$1000"){
        ret = 3;
    }
    else if (value == "$1000-$2000"){
        ret = 2;
    }
    else if (value == "$2000-$3000"){
        ret = 1;
    }
    else {
        ret = 1;
    }
    return ret;
}

int databasemanager::clawStateConversion(QString value)
{
    int ret = 0;
    if (value == "Removed"){
        ret = 1;
    }
    return ret;
}

int databasemanager::ageConversion(double value)
{
    int ret = 0;
    if (value < 3.0){
        ret = 4;
    }
    else if (value >=3 && value <= 10){
        ret = 3;
    }
    else if (value > 10 && value <= 20){
        ret = 2;
    }
    else {
        ret = 1;
    }
    return ret;
}

void databasemanager::createAnimalObjects()
{
    QSqlQuery qry;
    qry.prepare("SELECT Count(*) from animal");
    qry.exec();
    qry.next();
    int maxSize = qry.value(0).toInt();

    for (int i=1; i<=maxSize; i++){
        qry.prepare("SELECT age,houstrained,specialNeeds,playfulness,costOfCare,sheddingAmount,"
                    "aggression,solitudialBehaviour,diseaseResistance,parasiticResistance,goodforNOwners,"
                    "easeOfTraining,vocal,clawState, name, type from animal WHERE animal_id = '"+QString::number(i)+"'");
        qry.exec();
        qry.next();
        QVector<int> att;

        //age
        att.append(ageConversion(qry.value(0).toDouble()));
        //housetrained
        att.append(yesOrNoConversion(qry.value(1).toString()));
        //special
        att.append(highGoodConversion(qry.value(2).toString()));
        //playfulness
        att.append(highGoodConversion(qry.value(3).toString()));
        //cost
        att.append(lowGoodConversion(qry.value(4).toString()));
        //shedding
        att.append(highGoodConversion(qry.value(5).toString()));
        //aggression
        att.append(highGoodConversion(qry.value(6).toString()));
        //solitude
        att.append(highGoodConversion(qry.value(7).toString()));
        //disease
        att.append(yesOrNoConversion(qry.value(8).toString()));
        //parasite
        att.append(highGoodConversion(qry.value(9).toString()));
        //novice
        att.append(lowGoodConversion(qry.value(10).toString()));
        //ease
        att.append(clawStateConversion(qry.value(11).toString()));
        //vocal
        att.append(lowGoodConversion(qry.value(12).toString()));
        //claw
        att.append(clawStateConversion(qry.value(13).toString()));

        animals.insert(qry.value(14).toString(),factory->create(att, qry.value(15).toString()));
    }
}

bool databasemanager::editClientPrefInfo(QVector<QString> v)
{
    QSqlQuery qry;
    bool ret = false;

    qry.prepare("UPDATE client SET pAnimaltype = '"+v.at(0)+"', pAnimalbreed = '"+v.at(1)+"', ageRange = '"+v.at(2)+"', prefEnvtype = '"+v.at(3)+"', vetFees = '"+v.at(4)+"', kidFriendly = '"+v.at(5)+"', easeTrain = '"+v.at(6)+"', healthCon = '"+v.at(7)+"', prefSize = '"+v.at(8)+"' WHERE name = '"+v.at(9)+"'");
    ret = qry.exec();
    return ret;
}








