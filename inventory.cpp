#include "inventory.h"
#include <QKeyEvent>
#include <QGraphicsScene>
#include <QDebug>

Inventory::Inventory()
{

}

void Inventory::showInventory()
{
    Item *itemDesc;
    QString itemDesc1;
    int i=0;
    while(  i < itemsInInventory.size())
    {
       itemDesc = itemsInInventory[i];
       itemDesc1 = itemDesc->getDescription();
       i++;
    }
}

void Inventory::addToInventory(Item *item)
{
    itemsInInventory.push_back(item);
}

vector<Item*> Inventory:: getInventoryList()
{
    return itemsInInventory;
}

void Inventory::setInventoryList(vector<Item *> InventoryList)
{
    this->itemsInInventory=InventoryList;
}

int Inventory::inventoryQty()
{
    return itemsInInventory.size();
}
