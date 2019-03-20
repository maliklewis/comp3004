#include "animalfactory.h"

//AnimalFactory::AnimalFactory() {}

Animal* AnimalFactory::create(QVector<int> attributes, QString name)
{
    return (new Dog(attributes, name));
}
