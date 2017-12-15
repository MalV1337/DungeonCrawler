#include "Tile.h"
#include "Character.h"

Tile::Tile() {
    m_character = nullptr;
}

Tile::Tile(Character* c) {
    m_character = c;
}


Tile::~Tile() {
	m_character = nullptr;
}

Character* Tile::getCharacter() const {
    return m_character;
}

bool Tile::hasCharacter() const {
    if (m_character != nullptr) {
        return true;
    }
    return false;
}

void Tile::setCharacter(Character* c) {
    m_character = c;
}


void Tile::onLeave(Tile* toTile) {
}

void Tile::onEnter(Character* c, Tile* fromTile) {
	if (hasCharacter() == true) {
        fromTile->onEnter(c, this);
    } else {
        fromTile->setCharacter(nullptr);
        m_character = c;
    }
}

char Tile::getTileFromType() {
    return 0;
}

char Tile::save() {
    return 0;
}

bool Tile::isWalkable() {
    return 0;
}


bool Tile::isTransparent() {
    return true;
}










