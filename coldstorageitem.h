#ifndef COLDSTORAGEITEM_H
#define COLDSTORAGEITEM_H
#include "item.h"
#include <QDebug>

class coldstorageitem: public Item
{
    public:
        coldstorageitem(QString desc,int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};

#endif // COLDSTORAGEITEM_H
