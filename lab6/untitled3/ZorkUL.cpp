#include <iostream>
#include<cstdlib>
#include<ctime>

using namespace std;
#include "ZorkUL.h"

ZorkUL::ZorkUL() {
    srand(time(0));
    createRooms();
}

const int TREASURE_COUNT = 9;
const string TREASURE_NAMES[TREASURE_COUNT] = {"珍珠", "红宝石", "翡翠", "金戒", "蓝宝石", "紫晶", "钻石", "玛瑙", "琥珀"};

void ZorkUL::createRooms()  {
    Room *a, *b, *c, *d, *e, *f, *g, *h, *i, *j;

    a = new Room("a");
        a->addItem(new Treasure("珍珠", 100, 1000));
    b = new Room("b");
        b->addItem(new Treasure("红宝石", 100, 1000));
    c = new Room("c");
        c->addItem(new Treasure("翡翠", 100, 1000));
    d = new Room("d");
        d->addItem(new Treasure("金戒", 100, 1000));
    e = new Room("e");
        e->addItem(new Treasure("蓝宝石", 100, 1000));
    f = new Room("f");
        f->addItem(new Treasure("紫晶", 100, 1000));
    g = new Room("g");
        g->addItem(new Treasure("钻石", 100, 1000));
    h = new Room("h");
        h->addItem(new Treasure("玛瑙", 100, 1000));
    i = new Room("i");
        i->addItem(new Treasure("琥珀", 100, 1000));
    j = new Room("j");
             // N  E  S  W
    a->setExits(f, b, d, c);
    b->setExits(NULL, NULL, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, j);
    j->setExits(NULL,i,NULL,NULL);

        currentRoom = a;

        allRooms[0] = a;
        allRooms[1] = b;
        allRooms[2] = c;
        allRooms[3] = d;
        allRooms[4] = e;
        allRooms[5] = f;
        allRooms[6] = g;
        allRooms[7] = h;
        allRooms[8] = i;
        allRooms[9] = j;

        roomCount = 10;

        player = new Player("Player", 30);
}

bool ZorkUL::checkWin() {
    if (currentRoom->shortDescription() != "j") {
        return false;
    }
    for (int i = 0; i < TREASURE_COUNT; i++) {
        if (!player->hasItem(TREASURE_NAMES[i])) {
            return false;
        }
    }
    return true;
}

int ZorkUL::getCollectedTreasureCount() {
    int count = 0;
    for (int i = 0; i < TREASURE_COUNT; i++) {
        if (player->hasItem(TREASURE_NAMES[i])) {
            count++;
        }
    }
    return count;
}

string ZorkUL::getCollectedTreasures() {
    string result = "已收集的宝物:\n";
    for (int i = 0; i < TREASURE_COUNT; i++) {
        if (player->hasItem(TREASURE_NAMES[i])) {
            result += "[✓] " + TREASURE_NAMES[i] + "\n";
        } else {
            result += "[ ] " + TREASURE_NAMES[i] + "\n";
        }
    }
    return result;
}

string ZorkUL::takeAllTreasures() {
    string result = "";
    bool foundTreasure = false;
    
    for (int i = 0; i < TREASURE_COUNT; i++) {
        string treasureName = TREASURE_NAMES[i];
        int location = currentRoom->isItemInRoom(treasureName);
        if (location >= 0) {
            player->addItem(new Treasure(treasureName, 100, 1000));
            player->addScore(100);
            if (!result.empty()) {
                result += ", ";
            }
            result += treasureName;
            foundTreasure = true;
        }
    }
    
    if (!foundTreasure) {
        return "当前房间没有可拾取的宝物";
    } else {
        return "你拾取了: " + result;
    }
}

string ZorkUL::getMap() {
    string map = "         [h] --- [f] --- [g]\n";
    map += "                     |         \n";
    map += "                     |         \n";
    map += "         [c] --- [a] --- [b]\n";
    map += "                     |         \n";
    map += "                     |         \n";
    map += "[j] --- [i] --- [d] --- [e]\n";
    map += "\n当前位置: [" + currentRoom->shortDescription() + "]";
    return map;
}

int ZorkUL::getStamina() {
    return player->getStamina();
}

void ZorkUL::play() {
    printWelcome();

    bool finished = false;
    while (!finished) {
        Command* command = parser.getCommand();
        finished = processCommand(*command);
        delete command;
    }
    cout << endl;
    cout << "end" << endl;
}

void ZorkUL::printWelcome() {
    cout << "start"<< endl;
    cout << "info for help"<< endl;
    cout << endl;
    cout << currentRoom->longDescription() << endl;
}

bool ZorkUL::processCommand(Command command) {
    if (command.isUnknown()) {
        cout << "invalid input"<< endl;
        return false;
    }

    string commandWord = command.getCommandWord();
    if (commandWord.compare("info") == 0)
    {
        printHelp();
    }

    if (commandWord.compare("map") == 0)
        {
        cout << "[h] --- [f] --- [g]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[c] --- [a] --- [b] --- [j]" << endl;
        cout << "         |         " << endl;
        cout << "         |         " << endl;
        cout << "[i] --- [d] --- [e]" << endl;
        }

    else if (commandWord.compare("go") == 0) {
        goRoom(command);
        if (over) {
            return true;
        }
    }

    else if (commandWord.compare("take") == 0)
    {
        if (!command.hasSecondWord()) {
            cout << "incomplete input"<< endl;
        }
        else {
            string itemName = command.getSecondWord();
            cout << "you're trying to take " + itemName << endl;
            int location = currentRoom->isItemInRoom(itemName);
            if (location < 0) {
                cout << "item is not in room" << endl;
            } else {
                cout << "you took the " + itemName << endl;
                player->addItem(new Treasure(itemName, 100, 1000));
                player->addScore(100);
                cout << currentRoom->longDescription() << endl;
            }
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }

    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true;
    }

    else if(commandWord.compare("tp") == 0)
    {
        teleportRandom();
    }

    else if(commandWord.compare("currentroom") == 0)
    {
        cout << "Your current room is " ;
        cout << currentRoom->shortDescription() <<endl;
    }


    return false;
}

void ZorkUL::printHelp() {
    cout << "valid inputs are; " << endl;
    parser.showCommands();

}

void ZorkUL::goRoom(Command command) {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        return;
    }

    string direction = command.getSecondWord();

    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        player->consumeStamina();
        cout << currentRoom->longDescription() << endl;
        if (player->isDead()) {
            cout << "You have run out of stamina! Game over!" << endl;
            over = true;
            return;
        }
        if (checkWin()) {
            cout << "Congratulations! You have collected all treasures and reached room j! You win!" << endl;
            over = true;
        }
    }
}

string ZorkUL::go(string direction) {
    Room* nextRoom = currentRoom->nextRoom(direction);
    if (nextRoom == NULL)
        return("direction null");
    else
    {
        currentRoom = nextRoom;
        return currentRoom->longDescription();
    }
}

void ZorkUL::teleportRandom() {
    int r = rand() % roomCount;
    currentRoom = allRooms[r];
    player->consumeStamina();
    cout << "You are in the room " << currentRoom->shortDescription() << " now"<<endl;
    if (player->isDead()) {
        cout << "You have run out of stamina! Game over!" << endl;
        over = true;
    }
}

string ZorkUL::teleport() {
    teleportRandom();
    return currentRoom->longDescription();
}

Character& ZorkUL::getCharacter() {
    return *player;
}

bool ZorkUL::update() {
    return over;
}

void ZorkUL::createItems() {
}

void ZorkUL::displayItems() {
}

string ZorkUL::getCurrentRoomDescription() {
    return currentRoom->longDescription();
}