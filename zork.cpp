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
    delete bills;
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
    bills=new billing("BILLS",30);
    a= new Room("BILLING : Click on the Cash button to pay by by Cash. Alternatively, click on the Card button to pay by card.");
    a->addItem(bills);
    a->setItem(true);
    b= new Room("CAFE : Click on 'Prepare Beverages'");
    b->addItem(hotdrinks);
    b->setItem(true);
    c= new Room("STORAGE : Click on 'Collect Raw Materials' ");
    c->addItem(storedfood);
    c->setItem(true);
    d= new Room("DISHWASHER : Click on 'Wash Dishes' to continue");
    d->addItem(dishes);
    d->setItem(true);
    e= new Room("LOUNGE : Select alcohol from drop down box to continue. Click on serve beverage twice to proceed.");
    e->addItem(ambience);
    e->setItem(true);
    f= new Room("DINING : Click on 'Collect Dishes' to vollect already dirty dishes");
    f->addItem(eatenfood);
    f->setItem(true);
    g= new Room("BAR : Click on 'Make Drinks' ");
    g->addItem(drinks);
    g->setItem(true);
    h= new Room("KITCHEN : Click on 'Collect Order' ");
    h->addItem(cookedfood);
    h->setItem(true);
    i= new Room("COLD STORAGE : Click on the button 'Collect Cold Items' ");
    i->addItem(coldfood);
    i->setItem(true);
    j= new Room("WELCOME : Click on Start");
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

