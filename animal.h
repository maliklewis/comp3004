#ifndef ANIMAL_H
#define ANIMAL_H
#include <QVector>
#include <QMap>
#include <QDebug>


class Animal
{
public:
    Animal();
    Animal(QString,QString, QString,QString,QString,QString,QString,QString,QString,QString,QString,QString
           ,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString,QString);
    //virtual void setAttributes(QVector<int>) = 0;

    QString id;
    QString name;
    QString type;
    QString breed;
    QString gender;
    QString age;
    QString houseTrained;
    QString specialNeeds;
    QString lifespan;
    QString size;
    QString costOfCare;
    QString sheddingAmount;
    QString aggression;
    QString playfulness;
    QString behaviour;
    QString disease;
    QString parasite;
    QString goodForNOwners;
    QString easeOfTraining;
    QString environmentType;
    QString winged;
    QString vocal;
    QString clawState;

};

#endif // ANIMAL_H
