#include "kitchen.h"
#include <QDebug>

kitchen::kitchen(QString desc, int inW) : description(desc), weight(inW)
{
    this->setPixmap(QPixmap(":/Images/kitchen.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString kitchen::getDescription()
{
    return description;
}

bool kitchen:: getInvFlag()
{
    return this->invFlag;
}
