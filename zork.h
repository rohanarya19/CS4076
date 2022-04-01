#ifndef ZORK_H
#define ZORK_H
#include <QWidget>
#include <QGraphicsView>
#include <QGraphicsScene>
#include "player.h"
#include "myvector.h"
#include "key.h"
#include "teleporter.h"
#include "potion.h"
#include "weapon.h"
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
        myVector<QString> * controls;
        Key * key;
        Teleporter *teleporter;
        Potion * potion;
        Weapon * weapon;
        Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;
        Room *currentRoom;
        myVector<Room*> rooms;
};

#endif // ZORK_H
