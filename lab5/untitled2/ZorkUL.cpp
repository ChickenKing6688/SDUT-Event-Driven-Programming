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
        a->addItem(new Item("珍珠", 100, 1000));
    b = new Room("b");
        b->addItem(new Item("红宝石", 100, 1000));
    c = new Room("c");
        c->addItem(new Item("翡翠", 100, 1000));
    d = new Room("d");
        d->addItem(new Item("金戒", 100, 1000));
    e = new Room("e");
        e->addItem(new Item("蓝宝石", 100, 1000));
    f = new Room("f");
        f->addItem(new Item("紫晶", 100, 1000));
    g = new Room("g");
        g->addItem(new Item("钻石", 100, 1000));
    h = new Room("h");
        h->addItem(new Item("玛瑙", 100, 1000));
    i = new Room("i");
        i->addItem(new Item("琥珀", 100, 1000));
    j = new Room("j");

//             (N, E, S, W)
    a->setExits(f, b, d, c);
    b->setExits(NULL, j, NULL, a);
    c->setExits(NULL, a, NULL, NULL);
    d->setExits(a, e, NULL, i);
    e->setExits(NULL, NULL, NULL, d);
    f->setExits(NULL, g, a, h);
    g->setExits(NULL, NULL, NULL, f);
    h->setExits(NULL, f, NULL, NULL);
    i->setExits(NULL, d, NULL, NULL);
    j->setExits(NULL,NULL,NULL,b);

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

        character = new Character("Player", 30);
}

bool ZorkUL::checkWin() {
    if (currentRoom->shortDescription() != "j") {
        return false;
    }
    for (int i = 0; i < TREASURE_COUNT; i++) {
        if (!character->hasItem(TREASURE_NAMES[i])) {
            return false;
        }
    }
    return true;
}

int ZorkUL::getCollectedTreasureCount() {
    int count = 0;
    for (int i = 0; i < TREASURE_COUNT; i++) {
        if (character->hasItem(TREASURE_NAMES[i])) {
            count++;
        }
    }
    return count;
}

string ZorkUL::getCollectedTreasures() {
    string result = "已收集的宝物:\n";
    for (int i = 0; i < TREASURE_COUNT; i++) {
        if (character->hasItem(TREASURE_NAMES[i])) {
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
            character->addItem(new Item(treasureName, 100, 1000));
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
    string map = "[h] --- [f] --- [g]\n";
    map += "         |         \n";
    map += "         |         \n";
    map += "[c] --- [a] --- [b] --- [j]\n";
    map += "         |         \n";
    map += "         |         \n";
    map += "[i] --- [d] --- [e]\n";
    map += "\n当前位置: [" + currentRoom->shortDescription() + "]";
    return map;
}

int ZorkUL::getStamina() {
    return character->getStamina();
}


/**
 *  Main play routine.  Loops until end of play.
 */
void ZorkUL::play() {
    printWelcome();

    // Enter the main command loop.  Here we repeatedly read commands and
    // execute them until the ZorkUL game is over.

    bool finished = false;
    while (!finished) {
        // Create pointer to command and give it a command.
        Command* command = parser.getCommand();
        // Pass dereferenced command and check for end of game.
        finished = processCommand(*command);
        // Free the memory allocated by "parser.getCommand()"
        //   with ("return new Command(...)")
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

/**
 * Given a command, process (that is: execute) the command.
 * If this command ends the ZorkUL game, true is returned, otherwise false is
 * returned.
 */
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
                character->addItem(new Item(itemName, 100, 1000));
                cout << currentRoom->longDescription() << endl;
            }
        }
    }

    else if (commandWord.compare("put") == 0)
    {

    }
    /*
    {
    if (!command.hasSecondWord()) {
        cout << "incomplete input"<< endl;
        }
        else
            if (command.hasSecondWord()) {
            cout << "you're adding " + command.getSecondWord() << endl;
            itemsInRoom.push_Back;
        }
    }
*/
    else if (commandWord.compare("quit") == 0) {
        if (command.hasSecondWord())
            cout << "overdefined input"<< endl;
        else
            return true; /**signal to quit*/
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
/** COMMANDS **/
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

    // Try to leave current room.
    Room* nextRoom = currentRoom->nextRoom(direction);

    if (nextRoom == NULL)
        cout << "underdefined input"<< endl;
    else {
        currentRoom = nextRoom;
        cout << currentRoom->longDescription() << endl;
        if (checkWin()) {
            cout << "Congratulations! You have collected all treasures and reached room j! You win!" << endl;
            over = true;
        }
    }
}

string ZorkUL::go(string direction) {
    //Make the direction lowercase
    //transform(direction.begin(), direction.end(), direction.begin(),:: tolower);
    //Move to the next room
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
    cout << "You are in the room " << currentRoom->shortDescription() << " now"<<endl;
}

string ZorkUL::teleport() {
    teleportRandom();
    return currentRoom->longDescription();
}

Character& ZorkUL::getCharacter() {
    return *character;
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
