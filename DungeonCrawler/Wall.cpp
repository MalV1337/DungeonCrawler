#include "Wall.h"
#include "Floor.h"

Wall::Wall() {
    m_character = nullptr;
}

Wall::Wall(const Wall& orig) {
}

Wall::~Wall() {
}

void Wall::onLeave(Tile* toTile) { 
}

void Wall::onEnter(Character* c, Tile* fromTile) {
}

char Wall::getTileFromType() {
    return '#';
}

char Wall::save() {
    return getTileFromType();
}

bool Wall::isTransparent() {
    return false;
}

bool Wall::isWalkable() {
    return false;
}


