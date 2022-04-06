#include "zork.h"
#include "player.h"
#include <QImage>
#include <QGraphicsPixmapItem>

Zork::Zork(QWidget *parent)
{
    this->setAttribute(Qt::WA_DeleteOnClose);
    currentRoom=createRooms();
    createExits();
}

Zork::~Zork()
{
    delete player;
    delete a;
    delete b;
    delete c;
    delete d;
    delete e;
    delete f;
    delete g;
    delete h;
    delete i;
    delete j;
    delete drinks;
    delete coldfood;
    delete storedfood;
    delete cookedfood;
    delete eatenfood;
    delete hotdrinks;
    delete ambience;
    delete dishes;
}

Player* Zork::play()
{
    player = new Player();
    return player;
}

Room * Zork::createRooms()
{
    coldfood=new coldstorageitem("COLD ITEM",30);
    storedfood=new storageitem("STORAGE ITEM",30);
    cookedfood=new kitchen("COOKED FOOD",30);
    eatenfood=new dining("DIRTY DISHES",30);
    drinks=new bar("ALCOHOL",30);
    hotdrinks=new cafe("HOT BEVERAGE",30);
    ambience=new lounge("AMBIENCE",30);
    dishes=new dishwasher("DISHES",30);
    a= new Room("a");
    b= new Room("CAFE");
    b->addItem(hotdrinks);
    b->setItem(true);
    c= new Room("STORAGE");
    c->addItem(storedfood);
    c->setItem(true);
    d= new Room("DISHWASHER");
    d->addItem(dishes);
    d->setItem(true);
    e= new Room("LOUNGE");
    e->addItem(ambience);
    e->setItem(true);
    f= new Room("DINING");
    f->addItem(eatenfood);
    f->setItem(true);
    g= new Room("BAR");
    g->addItem(drinks);
    g->setItem(true);
    h= new Room("KITCHEN");
    h->addItem(cookedfood);
    h->setItem(true);
    i= new Room("COLD STORAGE");
    i->addItem(coldfood);
    i->setItem(true);
    j= new Room("WELCOME");
    rooms+=a;
    rooms+=b;
    rooms+=c;
    rooms+=d;
    rooms+=e;
    rooms+=f;
    rooms+=g;
    rooms+=h;
    rooms+=i;
    rooms+=j;
    return j;
}

void Zork::createExits()
{
    // (N, E, S, W)
    a->setExits(NULL, NULL, NULL, NULL);
    b->setExits(NULL, NULL, e, NULL);
    c->setExits(h, NULL, NULL, NULL);
    d->setExits(a, NULL, NULL, NULL);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, NULL, NULL);
    g->setExits(NULL, NULL, b, NULL);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(c, NULL, NULL, NULL);
    j->setExits(i, NULL, NULL, NULL);
}

