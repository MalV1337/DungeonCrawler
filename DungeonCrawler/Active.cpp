#include "Active.h"

Active::Active():
m_passivePtr(nullptr)
{
    m_statusAc = false;
    m_character = nullptr;
}

Active::Active(const Active& orig) {
}

Active::~Active() {
}

bool Active::getAcStatus() const {
    return m_statusAc;
}

void Active::setAcStatus(bool state) {
    m_statusAc = state;
}

void Active::setPasPtr(Passive* pasPtr) {
    
}

char Active::getTileFromType() {
	return 0;
}

void Active::onEnter(Character* c, Tile* fromTile) {

}

void Active::onLeave(Tile* toTile) {

}



