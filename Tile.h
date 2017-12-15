#ifndef TILE_H
#define TILE_H

#include <algorithm>
#include <cstdlib>
#include <iostream>
#include <ctime>
#include <fstream>
#include <sstream>
#include <vector>
#include <stdexcept>
#include <typeinfo>
#include <queue>
#include <utility>
#include <cmath>
#include <limits>
#include <map>
#include <set>

using namespace std;

class Character;

class Tile {
public:
    Tile();
    Tile(Character* c);

    virtual ~Tile();
    Character* getCharacter() const;
    void setCharacter(Character* c);
    bool hasCharacter() const;
    virtual bool isTransparent();
    virtual bool isWalkable();
    virtual void onLeave(Tile* toTile);
    virtual void onEnter(Character* c, Tile* fromTile);
    virtual char getTileFromType();
    virtual char save();


protected:
    Character* m_character;
};


#endif 

