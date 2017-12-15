#include "Floor.h"
#include "Switch.h"
#include "Door.h"
#include "Lever.h"
#include "Trap.h"
#include "Character.h"

Floor::Floor() {
    m_item = nullptr;
    m_character = nullptr;
}

Floor::~Floor() {
}

Item* Floor::getItem() const {
    return m_item;
}

void Floor::setItem(Item* item) {
    m_item = item;
}

void Floor::onLeave(Tile* toTile) {
    toTile->onEnter(getCharacter(), this); // erst nullptr dann toTile FIXED
}

void Floor::onEnter(Character* c, Tile* fromTile) {
    if(!hasCharacter()){
        m_character = c;
        fromTile->setCharacter(nullptr);
        if(m_item != nullptr) {
            c->addItem(m_item);
            m_item = nullptr;
        }
    }
    else if(getCharacter() != c){ 
        if (!(getCharacter()->hit(c->getStrength()))) {
            c->hit(getCharacter()->getStrength());
            c->showInfo();
            getCharacter()->showInfo();  
            if(c->hit(0))
                fromTile->setCharacter(nullptr);
        } else {
            setCharacter(nullptr);
            c->showInfo();
        }
    }
}

char Floor::getTileFromType() {
    if(m_item != nullptr)
        return '*';
    else
        return '.';
}

char Floor::save() {
    return '.';
}


bool Floor::isTransparent() {
    return true;
}

bool Floor::isWalkable() {
    return true;
}





