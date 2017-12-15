#ifndef CHARACTER_H
#define CHARACTER_H

#include "DungeonMap.h"
#include "Controller.h"

class Controller;

class Item;

class Character {
public:
    Character(char c, int strength, int stamina, Controller* controller);
    Character(const Character& orig);
    virtual ~Character();
    friend ostream& operator<<(ostream& outputstream, const Character& character);
    char getCharacter() const;
    Controller* getController();
    void setController(Controller* control);
    int move();

    int getMaxHP() const;
    void showInfo() const;

    void addItem(Item* itemObj);
    int getStamina() const;
    int getStrength() const;

    bool hit(int damage);
    bool isAlive();

private:
    char m_character;
    Controller* m_controller;
    vector<Item*> m_itemVec;
    int m_strength;
    int m_stamina;
    int m_hitpoints;
};

#endif 

