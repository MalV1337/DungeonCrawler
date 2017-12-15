#include "Switch.h"
#include "Floor.h"
#include "Door.h"
#include "DungeonMap.h"

Switch::Switch() {
    m_statusAc = false;
    m_character = nullptr;
}

Switch::Switch(const Switch& orig) {
}

Switch::~Switch() {

}

void Switch::setPasPtr(Passive* pasPtr) {
    m_passivePtr = pasPtr;
}

void Switch::onLeave(Tile* toTile) {
}

void Switch::onEnter(Character* c, Tile* fromTile) {
    m_statusAc = true; //aktivere den Switch 
    m_passivePtr->setPasStatus(true);
    fromTile->onEnter(c,this);
}

char Switch::getTileFromType() {
    if (m_statusAc) { //m_statusPas geschlossene Tür ist false
        return '!';
    }
    return '?';
}

char Switch::save() {
    return getTileFromType();
}

bool Switch::isWalkable() {
    return false;
}




