#ifndef TRAP_H
#define TRAP_H

#include "Floor.h"

class Trap: public Floor {
public:
    Trap();
    Trap(Item* item, int damage);
    virtual ~Trap();
    
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    char getTileFromType() override;
    bool isWalkable() override;
    char save() override;

private:
    bool m_trapStat;
    int m_dmgPoints;
};

#endif /* TRAP_H */

