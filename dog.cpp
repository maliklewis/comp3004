#include "dog.h"

Dog::Dog(QVector<int> a, QString name)
{
    setAttributes(a, name);
}

void Dog::setAttributes(QVector<int> a, QString name)
{
    attributes = { {"age", a.at(0)}, {"housetrained", a.at(1)}, {"special needs", a.at(2)},
                   {"cost of care", a.at(3)}, {"shedding amount", a.at(4)}, {"aggression", a.at(5)},
                   {"playfulness", a.at(6)}, {"solitudial behaviour", a.at(7)},
                   {"immune system", a.at(8) + a.at(9)}, {"good for novices owners", a.at(10)},
                   {"ease of training", a.at(11)},{"vocal", a.at(12)}, };

    qDebug()<< name <<" attributes: " << attributes.values();
}
