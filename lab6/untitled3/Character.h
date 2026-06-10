#ifndef CHARACTER_H_
#define CHARACTER_H_

#include<string>
#include<vector>
#include<QObject>

#include "Item.h"

using namespace std;

class Character : public QObject {
Q_OBJECT

protected:
    string       name;
    int          stamina;
    vector<Item*> itemsInCharacter;

public:
    Character(string name, int stamina);
    virtual ~Character();

    bool isDead();
    void consumeStamina();
    int getStamina();
    void setStamina(int stamina);
    
    void addItem(Item* item);
    void addItem(Item& item);
    void removeItem(string description);
    void removeItem(int index);
    
    virtual string longDescription();
    string getName();
    int getItemCount();
    bool hasItem(string description);

    friend ostream& operator<<(ostream& os, const Character& character);
    friend bool operator==(const Character& c1, const Character& c2);
};

class Player : public Character {
private:
    int level;
    int score;

public:
    Player(string name, int stamina);
    
    int getLevel();
    void setLevel(int level);
    
    int getScore();
    void addScore(int points);
    
    void levelUp();
    string longDescription() override;
    
    Player& operator++();
    Player& operator++(int);
};

#endif // CHARACTER_H_