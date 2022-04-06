#include "bar.h"
#include <string>
#include <QDebug>

bar::bar(const QString desc, const int inW):description(desc), weight(inW)
{
    this->setPixmap(QPixmap(":/Images/bar.png"));
    this->setPos(470,100);
    this->setZValue(4);
    this->setScale(.4);
    invFlag = true;
}

QString bar:: getDescription()
{
    return description;
}

bool bar:: getInvFlag()
{
    return this->invFlag;
}


