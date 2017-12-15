#ifndef SWITCH_H
#define SWITCH_H

#include "Active.h"

class Door;

class Switch: public Active {
public:
    Switch();
    virtual ~Switch();
    
    char getTileFromType() override;
    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    void setPasPtr(Passive* pasPtr) override;
    char save() override;
    bool isWalkable() override;

    Door* getDoor() const;
    void setDoor(Door* d);
    
private:
    Switch(const Switch& orig);
};

#endif /* SWITCH_H */

