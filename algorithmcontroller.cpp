#include "algorithmcontroller.h"

AlgorithmController::AlgorithmController(){}

void AlgorithmController::initMatches()
{
    databasemanager* cuacsdb = databasemanager::getInstance();

    animalList=cuacsdb->animalList;
    clientList=cuacsdb->clientList;

    for(int i=0; i<clientList.length(); i++){
        for(int j=0; j<animalList.length(); j++){

            if(clientList.at(i).value("animal type")==animalList.at(j).value("type")){

            }
        }
    }
}
