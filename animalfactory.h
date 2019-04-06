#ifndef ANIMALFACTORY_H
#define ANIMALFACTORY_H

#include "animal.h"
#include "dog.h"
#include "cat.h"
#include "bird.h"

class AnimalFactory
{
public:
    //AnimalFactory();
    Animal* create(QVector<int>, QString);
};

#endif // ANIMALFACTORY_H
