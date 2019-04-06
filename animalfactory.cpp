#include "animalfactory.h"

//AnimalFactory::AnimalFactory() {}

Animal* AnimalFactory::create(QVector<int> attributes, QString type)
{
    if (type == "Dog")
        return new Dog(attributes);
}


