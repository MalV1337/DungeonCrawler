#ifndef LEVER_H
#define LEVER_H

#include "Switch.h"

class Lever: public Switch {
public:
    Lever();
    Lever(const Lever& orig);
    virtual ~Lever();
    
    void onLeave(Tile* toTile) override;
    void onEnter(Character* c, Tile* fromTile) override;
    char save() override;
    char getTileFromType() override;
    bool isWalkable() override;

private:

};

#endif /* LEVER_H */

