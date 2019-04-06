#include "animalfactory.h"

//AnimalFactory::AnimalFactory() {}

Animal* AnimalFactory::create(QVector<int> attributes, QString type)
{
    if (type == "Dog"){
        return (new Dog(attributes));
    }
    if (type == "Cat"){
        return new Cat(attributes);
    }
    if (type == "Bird"){
        return new Bird(attributes);
    }
    return 0;
}


