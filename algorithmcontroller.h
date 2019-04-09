#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H

#include "databasemanager.h"



class AlgorithmController
{
public:
    static AlgorithmController* getInstance();
    void initMatches();
    QList<Animal> animalList;
    QList<Client> clientList;
    QMap<Client,QList<Animal>> initial;
    QList<QList<Animal>> aList;
    QList<QList<int>> scoreList;
    void scoreMatches();

private:
    static AlgorithmController* instance;
    AlgorithmController();


};

#endif // ALGORITHMCONTROLLER_H
