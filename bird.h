#ifndef BIRD_H
#define BIRD_H

#include "animal.h"

class Bird : public Animal
{
public:
    Bird(QVector<int>);
    void setAttributes(QVector<int>);

private:
    QMap<QString, int> attributes;
};

#endif // BIRD_H
