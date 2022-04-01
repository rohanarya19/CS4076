#ifndef ROOM_H
#define ROOM_H
#include <map>
#include <string>
#include <vector>
#include "item.h"

using namespace std;
using std::vector;

class Room
{
    private:
        map<string, Room*> exits;
        bool itemPresent=false;
        string description;
        bool canEnter;
    public:
        Room(string description);
        vector<Item*> itemsInRoom;
        Item *item;
        void setExits(Room *north, Room *east, Room *south, Room *west);
        void setItem(bool i);
        vector<string> exitString();
        string getDescription();
        bool itemInRoom();
        vector<Room> rooms();
        Room* nextRoom(string direction);
        void addItem(Item *inItem);
        void addItemToRoom(Room *room);
        int numberOfItems();
        bool getCanEnter();
        void setCanEnter(bool);
};

#endif // ROOM_H
