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

void AlgorithmController::initMatches()
{
    databasemanager* cuacsdb = databasemanager::getInstance();

    animalList=cuacsdb->animalList1;
    clientList=cuacsdb->clientList1;



    for (int i=0; i<clientList.size();i++){
        QList<Animal> aSubList;

        for(int j=0;j<animalList.size();j++){
            if((clientList.at(i).pAnimalType == animalList.at(j).type) && (clientList.at(i).pAnimalBreed == animalList.at(j).breed)){
                aSubList.append(animalList.at(j));
            }

        }
        aList.append(aSubList);
    }

    QString test0=clientList.at(3).name;
    QString test=aList.at(3).at(0).name;
    QString test1=aList.at(3).at(1).name;
   qDebug()<<test0+","+test+","+test1;



    //for (int i=0; i<initial.size();i++)

    //qDebug()<<(clientList.at(0).name);
    //for (Client c : initial.keys()){
    //    qDebug()<<(c.name);
    //}
}

void AlgorithmController::scoreMatches(){
    for(int j=0;j<clientList.size();j++){

        for(int i=0;i<aList.at(j).size();i++){


            if(clientList.at(j).age == aList.at(j).at(i).age){
            //qDebug()<<"got here";
            //qDebug()<<clientList.at(j).name << ", " << clientList.at(j).age ;
                aList[j][i].score+=20;
            }

            if(clientList.at(j).income == aList.at(j).at(i).costOfCare){
                aList[j][i].score+=20;
                //qDebug()<<aList[j][i].score;

            }
            if(clientList.at(j).archStyle ==aList.at(j).at(i).size){
                aList[j][i].score+=20;
            }
            //client pref
            if(clientList.at(j).ageRange == aList.at(j).at(i).age){
                aList[j][i].score+=20;
            }
            if(clientList.at(j).pEnvType == aList.at(j).at(i).environmentType ){
                //qDebug()<<"got here";
                aList[j][i].score+=20;
            }
            if(clientList.at(j).vetFees ==aList.at(j).at(i).costOfCare){
                 aList[j][i].score+=20;
            }
            if(clientList.at(j).pSize ==aList.at(j).at(i).size){
                //qDebug()<<"got here";
                 aList[j][i].score+=20;
            }
            if(clientList.at(j).healthCondition == aList.at(j).at(i).specialNeeds){
                 aList[j][i].score+=20;
            }
        }

    }
    QString test = clientList.at(0).name;
    QString test2 = aList.at(0).at(0).name;
    qDebug()<< test << test2;
}


