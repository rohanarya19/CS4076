#ifndef STORAGEITEM_H
#define STORAGEITEM_H
#include "item.h"
#include <QDebug>

class storageitem: public Item
{
    public:
        storageitem(QString desc,int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};

#endif // STORAGEITEM_H
