#include "billing.h"
#include <string>
#include <QDebug>

billing::billing(const QString desc, const int inW):description(desc), weight(inW)
{
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString billing:: getDescription()
{
    return description;
}

bool billing:: getInvFlag()
{
    return this->invFlag;
}
