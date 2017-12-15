#include "Lever.h"
#include "Floor.h"

Lever::Lever() {
    m_character = nullptr;
    m_statusAc = false;
}

Lever::Lever(const Lever& orig) {
}

Lever::~Lever() {
}

void Lever::onLeave(Tile* toTile) {
}

void Lever::onEnter(Character* c, Tile* fromTile) {
    if(m_statusAc){
            m_statusAc = false; //aktivere den Switch 
            m_passivePtr->setPasStatus(false); //sette Doorstatus auf true 
        }
        else{
            m_statusAc = true;
            m_passivePtr->setPasStatus(true);
        }
    fromTile->onEnter(c,this);
}

char Lever::save() {
    return getTileFromType();
}


char Lever::getTileFromType() {
    if (m_statusAc) { //m_statusPas geschlossene Tür ist false
        return 'L';
    }
    return 'l';
}

bool Lever::isWalkable() {
    return false;
}




