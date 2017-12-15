#ifndef FLOOR_H
#define FLOOR_H

#include "Tile.h"
#include "Character.h"

class Item;

class Floor: public Tile{
public:
    Floor();
    virtual ~Floor();
    
    Item* getItem() const;
    void setItem(Item* item);
    
    char save() override;
    char getTileFromType();
    
    bool isTransparent() override;
    bool isWalkable() override;

    void onLeave(Tile* toTile);
    void onEnter(Character* c, Tile* fromTile);

private:
    Item* m_item;
};

#endif /* FLOOR_H */

