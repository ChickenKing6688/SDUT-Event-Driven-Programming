#include "Room.h"

Room::Room(string description) {
	this->description = description;
}

Room::~Room() {
    for (Item* item : itemsInRoom) {
        delete item;
    }
    itemsInRoom.clear();
}

void Room::setExits(Room *north, Room *east, Room *south, Room *west) {
	if (north != NULL)
		exits["north"] = north;
	if (east != NULL)
		exits["east"] = east;
	if (south != NULL)
		exits["south"] = south;
	if (west != NULL)
		exits["west"] = west;
}

void Room::setExits(map<string, Room*> exits) {
    this->exits = exits;
}

string Room::shortDescription() {
	return description;
}

string Room::longDescription() {
	return "room = " + description + ".\n" + displayItem() + exitString();
}

string Room::exitString() {
	string returnString = "\nexits =";
	for (map<string, Room*>::iterator i = exits.begin(); i != exits.end(); i++)
		returnString += "  " + i->first;
	return returnString;
}

Room* Room::nextRoom(string direction) {
	map<string, Room*>::iterator next = exits.find(direction);
	if (next == exits.end())
		return NULL;
	return next->second;
}

void Room::addItem(Item *inItem) {
    itemsInRoom.push_back(inItem);
}

void Room::addItem(Item& inItem) {
    itemsInRoom.push_back(new Treasure(inItem.getShortDescription(), inItem.getWeight(), inItem.getValue()));
}

string Room::displayItem() {
    string tempString = "items in room = ";
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        tempString = "no items in room";
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            tempString = tempString + itemsInRoom[x]->getShortDescription() + "  " ;
            x++;
            }
        }
    return tempString;
    }

unsigned long Room::numberOfItems() {
    return itemsInRoom.size();
}

int Room::isItemInRoom(string inString)
{
    int sizeItems = (itemsInRoom.size());
    if (itemsInRoom.size() < 1) {
        return -1;
        }
    else if (itemsInRoom.size() > 0) {
       int x = (0);
        for (int n = sizeItems; n > 0; n--) {
            int tempFlag = inString.compare(itemsInRoom[x]->getShortDescription());
            if (tempFlag == 0) {
                delete itemsInRoom[x];
                itemsInRoom.erase(itemsInRoom.begin()+x);
                return x;
            }
            x++;
            }
        }
    return -1;
}

void Room::removeItemFromRoom(int location) {
    if (location >= 0 && location < static_cast<int>(itemsInRoom.size())) {
        delete itemsInRoom[location];
        itemsInRoom.erase(itemsInRoom.begin() + location);
    }
}

Room& Room::operator=(const Room& other) {
    if (this != &other) {
        this->description = other.description;
        this->exits = other.exits;
        for (Item* item : itemsInRoom) {
            delete item;
        }
        itemsInRoom.clear();
        for (const Item* item : other.itemsInRoom) {
            itemsInRoom.push_back(new Treasure(item->getShortDescription(), item->getWeight(), item->getValue()));
        }
    }
    return *this;
}

bool Room::operator==(const Room& other) const {
    return this->description == other.description;
}

ostream& operator<<(ostream& os, const Room& room) {
    os << "Room: " << room.description;
    return os;
}

TreasureRoom::TreasureRoom(string description) : Room(description), hasTreasure(true) {}

void TreasureRoom::setTreasure(bool has) {
    hasTreasure = has;
}

bool TreasureRoom::getTreasure() {
    return hasTreasure;
}

string TreasureRoom::longDescription() {
    string base = Room::longDescription();
    if (hasTreasure) {
        base += "\nThis room contains a treasure!";
    }
    return base;
}