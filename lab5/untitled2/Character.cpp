#include "Character.h"

Character::Character(string name, int stamina) {
    this->name = name;
    this->stamina = stamina;
}

bool Character::isDead() {
    return stamina <= 0;
}

void Character::consumeStamina() {
    stamina--;
}

int Character::getStamina() {
    return stamina;
}

void Character::addItem(Item& item) {
    itemsInCharacter.push_back(item);
}

void Character::addItem(Item *item) {
    itemsInCharacter.push_back(*item);
    delete item;
}

string Character::longDescription() {
    string ret = this->name;
    ret += "\n Item list:\n";
    for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        ret += "\t" + (*i).getLongDescription() + "\n";
    return ret;
}

string Character::getName() {
    return name;
}

int Character::getItemCount() {
    return itemsInCharacter.size();
}

bool Character::hasItem(string description) {
    for (vector<Item>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++) {
        if ((*i).getShortDescription() == description) {
            return true;
        }
    }
    return false;
}
