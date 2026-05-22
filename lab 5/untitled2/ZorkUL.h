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

    string printWelcome();
    string go(string direction);
    string teleport();

    Character& getCharacter();

signals:
    void state_updated();
    void game_over();

private:
    Parser parser;

    Character* character;
    Room*      currentRoom;

    bool over;
    vector<Room*> rooms;

    bool update();
    void createRooms();
    bool processCommand(Command command);
    void printHelp();
    void goRoom(Command command);
    void createItems();
    void displayItems();
};

#endif /*ZORKUL_H_*/
