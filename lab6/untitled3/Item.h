#ifndef ITEM_H_
#define ITEM_H_

#include<string>
#include<iostream>

using namespace std;

class Item {
protected:
    string description;
    string longDescription;
    int    weightGrams;
    float  value;

public:
    Item(string description, int inWeight, float inValue);
    Item(string description);

    virtual string getShortDescription() const;
    virtual string getLongDescription() const;

    int getWeight() const;
    void setWeight(int weightGrams);

    float getValue() const;
    void setValue(float value);

    virtual void use() = 0;
    virtual ~Item() {}
};

class Weapon : public Item {
private:
    int damage;

public:
    Weapon(string description, int inWeight, float inValue, int damage);
    int getDamage();
    void setDamage(int damage);
    void use() override;
};

class Treasure : public Item {
private:
    bool isCollected;

public:
    Treasure(string description, int inWeight, float inValue);
    bool getIsCollected();
    void setIsCollected(bool collected);
    void use() override;
};

#endif /*ITEM_H_*/