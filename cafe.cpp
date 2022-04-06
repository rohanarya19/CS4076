#include "cafe.h"
#include <string>
#include <QDebug>

cafe::cafe(const QString desc, const int inW):description(desc), weight(inW)
{
    this->setPixmap(QPixmap(":/Images/cafe.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString cafe:: getDescription()
{
    return description;
}

bool cafe:: getInvFlag()
{
    return this->invFlag;
}


