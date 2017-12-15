#include "Door.h"
#include "Active.h"

Door::Door(){
    m_statusPas = false;
}

Door::Door(const Door& orig) {
}

Door::~Door() {
}

char Door::save() {
    return getTileFromType();
}


char Door::getTileFromType() {
    if (m_statusPas) {      //m_statusPas geschlossene Tür ist false
        return '/';
    }
    else
        return 'X';
}

void Door::onLeave(Tile* toTile) {
    toTile->onEnter(getCharacter(), this); // erst nullptr dann toTile FIXED
}


void Door::onEnter(Character* c, Tile* fromTile) {
    if (this->getPasStatus() == false) {
        fromTile->onEnter(c, this);
    } else {
        this->setCharacter(c);
        fromTile->setCharacter(nullptr);
    }
}

Passive* Door::getPasObj() {
    return this;
}

bool Door::getPasStatus() const {
    return m_statusPas;
}

void Door::setPasStatus(bool state) {
    m_statusPas = state;
}

bool Door::isTransparent() {
    if(getPasStatus())
        return true;
    else 
        return false;
}

bool Door::isWalkable() {
    if(getPasStatus())
        return true;
    else 
        return false;
}










