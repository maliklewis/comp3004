#ifndef DOG_H
#define DOG_H

#include "animal.h"


class Dog : public Animal
{
public:
    Dog(QVector<int>, QString);
    void setAttributes(QVector<int>, QString);

private:
    QMap<QString,int> attributes;
};

#endif // DOG_H
