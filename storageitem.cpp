#include "storageitem.h"
#include <QDebug>

storageitem::storageitem(QString desc, int inW) : description(desc), weight(inW)
{
    this->setPixmap(QPixmap(":/Images/storageitem.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString storageitem::getDescription()
{
    return description;
}

bool storageitem:: getInvFlag()
{
    return this->invFlag;
}
