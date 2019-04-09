#ifndef CLIENT_H
#define CLIENT_H
#include <QVector>
#include <QMap>
#include <QDebug>
#include "animal.h"

class Client
{
public:
    Client();
    Client(QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);

    bool operator< (const Client&);

    QString id;
    QString name;
    QString number;
    QString email;
    QString age;
    QString numChildren;
    QString ageOfChilden;
    QString otherAnimals;
    QString empType;
    QString maritalStatus;
    QString empStatus;
    QString income;
    QString archStyle;
    QString pAnimalType;
    QString pAnimalBreed;
    QString ageRange;
    QString pEnvType;
    QString vetFees;
    QString kidFriendly;
    QString easeOfTraining;
    QString healthCondition;
    QString pSize;
    //QList<Animal> List = {};

};

#endif // CLIENT_H
