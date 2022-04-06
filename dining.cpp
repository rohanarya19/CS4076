#include "dining.h"
#include <QDebug>

dining::dining(QString desc, int inW) : description(desc), weight(inW)
{
    this->setPixmap(QPixmap(":/Images/dining.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString dining::getDescription()
{
    return description;
}

bool dining:: getInvFlag()
{
    return this->invFlag;
}
