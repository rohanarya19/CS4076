#ifndef KITCHEN_H
#define KITCHEN_H
#include "item.h"
#include <QDebug>

class kitchen: public Item
{
    public:
        kitchen(QString desc,int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};
#endif // KITCHEN_H
