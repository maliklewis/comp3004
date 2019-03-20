#ifndef ANIMAL_H
#define ANIMAL_H
#include <QVector>
#include <QMap>
#include <QDebug>


class Animal
{
public:
    Animal();
    virtual void setAttributes(QVector<int>, QString) = 0;
};

#endif // ANIMAL_H
