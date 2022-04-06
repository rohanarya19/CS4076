#include "dishwasher.h"
#include <QDebug>

dishwasher::dishwasher(QString desc, int inW) : description(desc), weight(inW)
{
    this->setPos(450,200);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString dishwasher::getDescription()
{
    return description;
}

bool dishwasher:: getInvFlag()
{
    return this->invFlag;
}
