#include "coldstorageitem.h"
#include <QDebug>

coldstorageitem::coldstorageitem(QString desc, int inW) : description(desc), weight(inW)
{
    this->setPixmap(QPixmap(":/Images/coldstorageitems.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString coldstorageitem::getDescription()
{
    return description;
}

bool coldstorageitem:: getInvFlag()
{
    return this->invFlag;
}
