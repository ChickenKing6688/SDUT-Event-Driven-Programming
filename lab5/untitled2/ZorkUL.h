#ifndef ZORKUL_H_
#define ZORKUL_H_

#include<iostream>
#include<string>
#include<QObject>

#include "Command.h"
#include "Parser.h"
#include "Room.h"
#include "Item.h"
#include "Character.h"

using namespace std;

class ZorkUL : public QObject {
Q_OBJECT

public:
    ZorkUL();
    void play();

    void printWelcome();
    string go(string direction);
    string teleport();

    Character& getCharacter();
    string getCurrentRoomDescription();
    int getCollectedTreasureCount();
    string getCollectedTreasures();
    string takeAllTreasures();
    bool checkWin();
    string getMap();
    int getStamina();

signals:
    void state_updated();
    void game_over();

private:
    Parser parser;

    Character* character;
    Room*      currentRoom;
    Room*      allRooms[10];
    int        roomCount;

    bool over;
    vector<Room*> rooms;

    bool update();
    void createRooms();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();
    void teleportRandom();
};

#endif /*ZORKUL_H_*/
