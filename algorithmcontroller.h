#ifndef ALGORITHMCONTROLLER_H
#define ALGORITHMCONTROLLER_H

#include "databasemanager.h"


class AlgorithmController
{
public:
    AlgorithmController();
    void initMatches();
    QVector<QMap<QString, QString>> animalList;
    QVector<QMap<QString, QString>> clientList;
    QMap<QMap<QString,QString>, QVector<QMap<QString, QString>>> initmatches;
};

#endif // ALGORITHMCONTROLLER_H
