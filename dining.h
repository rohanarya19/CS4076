#ifndef DINING_H
#define DINING_H
#include "item.h"
#include <QDebug>

class dining: public Item
{
    public:
        dining(QString desc,int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};
#endif // DINING_H
