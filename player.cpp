#include "player.h"

#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Player::Player()
{
    inventory = new Inventory();
}

Player::~Player()
{
    delete inventory;
}


Inventory * Player::getInventory()
{
    return inventory;
}






