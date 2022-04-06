#ifndef PLAYER_H
#define PLAYER_H
#include <QObject>
#include <QKeyEvent>
#include <QGraphicsPixmapItem>
#include "inventory.h"
#include <QMessageBox>

class Player
{
    public:
        Player();
        ~Player();
        Inventory * getInventory();
    private:
        Inventory* inventory;
};

#endif // PLAYER_H
