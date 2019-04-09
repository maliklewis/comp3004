#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H

#include "databasemanager.h"



class AlgorithmController
{
public:
    static AlgorithmController* getInstance();
   // QVector<QPair<QVector<QString>,QVector<QVector<QString>>>>initMatches();
    QVector<QVector<QString>> animalList;
    QVector<QVector<QString>> clientList;

    //QMap<QString,QVector<int>> giveScoreAttributes(QMap<QString,QVector<QString>>);

private:
    static AlgorithmController* instance;
    AlgorithmController();


};

#endif // ALGORITHMCONTROLLER_H
