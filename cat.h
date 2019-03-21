#ifndef CAT_H
#define CAT_H

#include "animal.h"

class Cat : public Animal
{
public:
    Cat(QVector<int>);
    void setAttributes(QVector<int>);

private:
    QMap<QString,int> attributes;
};

#endif // CAT_H
