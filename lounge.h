#ifndef LOUNGE_H
#define LOUNGE_H
#include "item.h"

class lounge: public Item
{
    public:
        lounge(const QString desc, const int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};
#endif // LOUNGE_H
