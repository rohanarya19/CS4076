#ifndef DISHWASHER_H
#define DISHWASHER_H
#include "item.h"

class dishwasher: public Item
{
    public:
        dishwasher(const QString desc, const int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};
#endif // DISHWASHER_H
