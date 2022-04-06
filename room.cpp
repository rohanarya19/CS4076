#include "Room.h"
#include <QDebug>

Room::Room(string description)
{
    this->description = description;
    canEnter=true;
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west)
{
    if (north != NULL)
        exits["north"] = north;
    if (east != NULL)
        exits["east"] = east;
    if (south != NULL)
        exits["south"] = south;
    if (west != NULL)
        exits["west"] = west;
}


void Room::setItem(bool i)
{
    if(i)
    {
        itemPresent=true;
    }
    else
    {
        itemPresent=false;
    }
}

vector<string> Room::exitString()
{
    vector<string> list;
    list.clear();
    map<string, Room*>::iterator i = exits.begin();
    while (i != exits.end() )
    {
        list.push_back(i->first);	// access the "first" element of the pair (direction as a string)
        i++;
    }
    return list;
}

string Room::getDescription()
{
    return description;
}

bool Room::itemInRoom()
{
    return itemPresent;
}

vector<Room> Room::rooms()
{
    vector<Room> list;
    list.clear();
    map<string, Room*>::iterator i = exits.begin();
    while ( i != exits.end())
    {
        list.push_back(i->first);	// access the "first" element of the pair (direction as a string)
        i++;
    }
    return list;
}

Room* Room::nextRoom(string direction)
{

    map<string, Room*>::iterator next = exits.find(direction); //returns an iterator for the "pair"
    if (next == exits.end())
    {
        return NULL; // if exits.end() was returned, there's no room in that direction.
    }
    return next->second; // If there is a room, remove the "second" (Room*), part of the "pair" (<string, Room*>) and return it.
}

void Room::addItem(Item *inItem)
{
    this->item =inItem;
    itemsInRoom.push_back(inItem);
}

int Room::numberOfItems()
{
    return itemsInRoom.size();
}

bool Room::getCanEnter()
{
    return canEnter;
}

void Room::setCanEnter(bool enter)
{
    this->canEnter=enter;
}

