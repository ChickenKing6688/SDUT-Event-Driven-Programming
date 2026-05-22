#ifndef CHARACTER_H_
#define CHARACTER_H_

#include<string>
#include<vector>
#include<QObject>

#include "Item.h"

using namespace std;

class Character : public QObject {
Q_OBJECT

public:
    Character(string name, int stamina);
    bool isDead();
    void consumeStamina();
    int getStamina();
    void addItem(Item& item);
    string longDescription();
    string getName();

private:
    string       name;
    int          stamina;
    vector<Item> itemsInCharacter;
};

#endif // CHARACTER_H_ */
