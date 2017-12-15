#include "Trap.h"
#include "Character.h"
#include "Item.h"

Trap::Trap() {
    m_character = nullptr;
    m_dmgPoints = -20;
    m_trapStat = false;
}

Trap::Trap(Item* item, int damage):
m_dmgPoints(damage),m_trapStat(false)
{
    m_character = nullptr;
}

Trap::~Trap() {
}

void Trap::onLeave(Tile* toTile) {
    toTile->onEnter(getCharacter(), this);
}

void Trap::onEnter(Character* c, Tile* fromTile) {
    if (!hasCharacter()) {
        setCharacter(c);
        fromTile->setCharacter(nullptr);
        if (m_trapStat == false) {
            c->hit(m_dmgPoints);
            m_trapStat = true;
        }
        if (getItem() != nullptr) {
            c->addItem(getItem());
            setItem(nullptr);
        }
    }
}

char Trap::getTileFromType() {
    if (hasCharacter())
        return getCharacter()->getCharacter();
    else if (getItem() != nullptr)
        return getItem()->getItemChar();
    else if (m_trapStat)
        return 'T';
    return '.';
}

char Trap::save() {
    if (!m_trapStat)
        return 't';
    else
        return 'T';
}

bool Trap::isWalkable() {
    return true;
}



