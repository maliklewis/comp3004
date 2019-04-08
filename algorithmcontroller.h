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
};

#endif // ALGORITHMCONTROLLER_H
