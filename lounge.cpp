#include "lounge.h"
#include <QDebug>

lounge::lounge(QString desc, int inW) : description(desc), weight(inW)
{
    this->setPos(450,200);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString lounge::getDescription()
{
    return description;
}

bool lounge:: getInvFlag()
{
    return this->invFlag;
}
