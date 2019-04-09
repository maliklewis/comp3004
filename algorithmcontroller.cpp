#include "algorithmcontroller.h"

AlgorithmController::AlgorithmController(){}

AlgorithmController* AlgorithmController::instance = 0;

AlgorithmController* AlgorithmController::getInstance()
{
    if (instance == 0)
    {
        instance = new AlgorithmController();
    }
    return instance;
}

/*QVector<QPair<QVector<QString>,QVector<QVector<QString>>>> AlgorithmController::initMatches()
{
    databasemanager* cuacsdb = databasemanager::getInstance();

    animalList=cuacsdb->animalList;
    clientList=cuacsdb->clientList;
    QVector<QPair<QVector<QString>,QVector<QVector<QString>>>> matchList;

    for(int i=0;i<clientList.size();i++){
        QVector<QString> list;
        for(int j=0;j<animalList.size();j++){

            if(clientList.at(i).at(3) == animalList.at(j).at(15)){//type is 3 and 15 for client and animal respectively
                if(clientList.at(i).at(4) == animalList.at(j).at(16)){//breed is 4 and 16 for client and animal respectively
                    list.append(animalList.at(j));
            if(clientList.at(i).value("animal type")==animalList.at(j).value("type")){
                if(clientList.at(i).value("animal breed")==animalList.at(j).value("breed")){

                }
            }

        }
        matchList.append(qMakePair(clientList.at(i),list));

     }
    return matchList;

}*/

/*QMap<QString,QVector<int>> AlgorithmController:: giveScoreAttributes(QMap<QString,QVector<QString>> map){
    databasemanager* cuacsdb = databasemanager::getInstance();

    animalList=cuacsdb->animalList;
    clientList=cuacsdb->clientList;

    for(int i=0;i<clientList.size();i++){
        int num =0;
        QVector<QString> list= map.value("'"+i+1+"'");
        for(int j=0;j<list.size();j++){
            //comapare the attributes of client(Age,income,architecture style,age) with the animal attributes (age, cost of care,size,life span) and add the scores


        }
    }

}*/

