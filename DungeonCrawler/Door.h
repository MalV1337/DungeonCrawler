#ifndef DOOR_H
#define DOOR_H

#include "Passive.h"
#include "Switch.h"

class Door: public Passive {
public:
    Door();
    virtual ~Door();
    
    char getTileFromType() override;
    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    bool isTransparent() override;
    char save() override;
    Passive* getPasObj() override;
    bool getPasStatus() const override;
    void setPasStatus(bool state) override;
    bool isWalkable() override;
    Switch* getSwitch() const;
    void setSwitch(Switch* s);

private:
    Door(const Door& orig);
};

#endif /* DOOR_H */

