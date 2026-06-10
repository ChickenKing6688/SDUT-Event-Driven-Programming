#ifndef ROOM_H_
#define ROOM_H_

#include<map>
#include<string>
#include<vector>

#include "Item.h"

using namespace std;

class Room {
private:
    string             description;
    map<string, Room*> exits;
    vector<Item>       itemsInRoom;

    string exitString();

public:
    Room(string description);

    void setExits(Room* north, Room* east, Room* south, Room* west);
    Room* nextRoom(string direction);

    string shortDescription();
    string longDescription();


    void addItem(Item *inItem);
    string displayItem();
    unsigned long numberOfItems();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
};

#endif
