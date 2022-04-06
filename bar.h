#ifndef BAR_H
#define BAR_H
#include "item.h"

class bar: public Item
{
    public:
        bar(const QString desc, const int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};

#endif // BAR_H
