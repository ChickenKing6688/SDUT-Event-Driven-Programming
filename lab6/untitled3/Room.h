#ifndef ROOM_H_
#define ROOM_H_

#include<map>
#include<string>
#include<vector>
#include<iostream>

#include "Item.h"

using namespace std;

class ZorkUL;

class Room {
private:
    string             description;
    map<string, Room*> exits;
    vector<Item*>       itemsInRoom;

    string exitString();

public:
    Room(string description);
    ~Room();

    void setExits(Room* north, Room* east, Room* south, Room* west);
    void setExits(map<string, Room*> exits);
    
    Room* nextRoom(string direction);
    
    string shortDescription();
    virtual string longDescription();

    void addItem(Item *inItem);
    void addItem(Item& inItem);
    
    string displayItem();
    unsigned long numberOfItems();
    int isItemInRoom(string inString);
    void removeItemFromRoom(int location);
    
    Room& operator=(const Room& other);
    bool operator==(const Room& other) const;
    
    friend class ZorkUL;
    friend ostream& operator<<(ostream& os, const Room& room);
};

class TreasureRoom : public Room {
private:
    bool hasTreasure;

public:
    TreasureRoom(string description);
    void setTreasure(bool has);
    bool getTreasure();
    string longDescription() override;
};

#endif