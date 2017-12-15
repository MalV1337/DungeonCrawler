#ifndef WALL_H
#define WALL_H

#include "Tile.h"

class Wall: public Tile {
public:
    Wall();
    Wall(const Wall& orig);
    virtual ~Wall();
    
    bool isTransparent() override;
    bool isWalkable() override;

    char save() override;
    char getTileFromType();
    void onLeave(Tile* toTile);
    void onEnter(Character* c, Tile* fromTile);

private:

};

#endif /* WALL_H */

