#include "Item.h"

Item::Item(string description, int inWeight, float inValue) {
    this->description = description;
    this->longDescription = "Item: " + description;
    this->weightGrams = inWeight;
    this->value = inValue;
}

Item::Item(string description) {
    this->description = description;
    this->longDescription = "Item: " + description;
    this->weightGrams = 0;
    this->value = 0;
}

string Item::getShortDescription() const {
    return description;
}

string Item::getLongDescription() const {
    return longDescription;
}

int Item::getWeight() const {
    return weightGrams;
}

void Item::setWeight(int weightGrams) {
    this->weightGrams = weightGrams;
}

float Item::getValue() const {
    return value;
}

void Item::setValue(float value) {
    this->value = value;
}

Weapon::Weapon(string description, int inWeight, float inValue, int damage)
    : Item(description, inWeight, inValue), damage(damage) {}

int Weapon::getDamage() {
    return damage;
}

void Weapon::setDamage(int damage) {
    this->damage = damage;
}

void Weapon::use() {
    cout << "使用武器: " << description << "，伤害: " << damage << endl;
}

Treasure::Treasure(string description, int inWeight, float inValue)
    : Item(description, inWeight, inValue), isCollected(false) {}

bool Treasure::getIsCollected() {
    return isCollected;
}

void Treasure::setIsCollected(bool collected) {
    isCollected = collected;
}

void Treasure::use() {
    cout << "收集宝物: " << description << "，价值: " << value << endl;
}