#include "Character.h"

Character::Character(string name, int stamina) : QObject(nullptr) {
    this->name = name;
    this->stamina = stamina;
}

Character::~Character() {
    for (Item* item : itemsInCharacter) {
        delete item;
    }
    itemsInCharacter.clear();
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

void Character::setStamina(int stamina) {
    this->stamina = stamina;
}

void Character::addItem(Item* item) {
    itemsInCharacter.push_back(item);
}

void Character::addItem(Item& item) {
    itemsInCharacter.push_back(new Treasure(item.getShortDescription(), item.getWeight(), item.getValue()));
}

void Character::removeItem(string description) {
    for (auto it = itemsInCharacter.begin(); it != itemsInCharacter.end(); ++it) {
        if ((*it)->getShortDescription() == description) {
            delete *it;
            itemsInCharacter.erase(it);
            return;
        }
    }
}

void Character::removeItem(int index) {
    if (index >= 0 && index < static_cast<int>(itemsInCharacter.size())) {
        delete itemsInCharacter[index];
        itemsInCharacter.erase(itemsInCharacter.begin() + index);
    }
}

string Character::longDescription() {
    string ret = this->name;
    ret += "\n Item list:\n";
    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        ret += "\t" + (*i)->getLongDescription() + "\n";
    return ret;
}

string Character::getName() {
    return name;
}

int Character::getItemCount() {
    return itemsInCharacter.size();
}

bool Character::hasItem(string description) {
    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++) {
        if ((*i)->getShortDescription() == description) {
            return true;
        }
    }
    return false;
}

ostream& operator<<(ostream& os, const Character& character) {
    os << "Character: " << character.name << ", Stamina: " << character.stamina;
    return os;
}

bool operator==(const Character& c1, const Character& c2) {
    return c1.name == c2.name && c1.stamina == c2.stamina;
}

Player::Player(string name, int stamina) : Character(name, stamina), level(1), score(0) {}

int Player::getLevel() {
    return level;
}

void Player::setLevel(int level) {
    this->level = level;
}

int Player::getScore() {
    return score;
}

void Player::addScore(int points) {
    score += points;
    if (score >= level * 1000) {
        levelUp();
    }
}

void Player::levelUp() {
    level++;
    stamina += 10;
}

string Player::longDescription() {
    string ret = "Player: " + name + " (Level " + to_string(level) + ")";
    ret += "\nScore: " + to_string(score) + ", Stamina: " + to_string(stamina);
    ret += "\nItem list:\n";
    for (vector<Item*>::iterator i = itemsInCharacter.begin(); i != itemsInCharacter.end(); i++)
        ret += "\t" + (*i)->getLongDescription() + "\n";
    return ret;
}

Player& Player::operator++() {
    levelUp();
    return *this;
}

Player& Player::operator++(int) {
    levelUp();
    return *this;
}