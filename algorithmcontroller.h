#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H

#include "databasemanager.h"



class AlgorithmController
{
public:
    static AlgorithmController* getInstance();
    void initMatches();
   // QVector<QPair<QVector<QString>,QVector<QVector<QString>>>>initMatches();
    QVector<QVector<QString>> animalList;
    QVector<QVector<QString>> clientList;

    //QMap<QString,QVector<int>> giveScoreAttributes(QMap<QString,QVector<QString>>);

private:
    static AlgorithmController* instance;
    AlgorithmController();

    //QVector<QMap<QString, QString>> animalList;
    //QVector<QMap<QString, QString>> clientList;
    //QMap<QMap<QString,QString>, QVector<QMap<QString, QString>>> initmatches;
};

#endif // ALGORITHMCONTROLLER_H
