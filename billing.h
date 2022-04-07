#ifndef BILLING_H
#define BILLING_H
#include "item.h"

class billing: public Item
{
    public:
        billing(const QString desc, const int inW);
        QString getDescription();
        bool getInvFlag();
    private:
        const QString description;
        const int weight;
};

#endif // BILLING_H
