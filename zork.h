#ifndef ZORK_H
#define ZORK_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"
#include "myvector.h"
#include "bar.h"
#include "coldstorageitem.h"
#include "storageitem.h"
#include "kitchen.h"
#include "dining.h"
#include "cafe.h"
#include "lounge.h"
#include "dishwasher.h"
#include "room.h"

class Zork : public QGraphicsView
{
    friend class Background;
    public:
        Zork(QWidget * parent=0);
        ~Zork();
        Player* play();
        Player* player;
        void createExits();
        Room * createRooms();
    private:
        bar * drinks;
        coldstorageitem * coldfood;
        storageitem * storedfood;
        kitchen * cookedfood;
        dining * eatenfood;
        cafe * hotdrinks;
        lounge * ambience;
        dishwasher * dishes;
        Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
        Room *currentRoom;
        myVector<Room*> rooms;
};

#endif // ZORK_H
