#ifndef CAFE_H
#define CAFE_H
#include "item.h"

class cafe: public Item
{
    public:
        cafe(const QString desc, const int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};

#endif // CAFE_H
