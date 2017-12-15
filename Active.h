#ifndef ACTIVE_H
#define ACTIVE_H

#include "Passive.h"

class Active: public Tile {
public:
    Active();
    Active(const Active& orig);
    virtual ~Active();
    
    bool getAcStatus() const;
    void setAcStatus(bool state);
    virtual void setPasPtr(Passive* pasPtr);
    
    void onEnter(Character* c, Tile* fromTile) override;
    void onLeave(Tile* toTile) override;
    char getTileFromType() override;

protected:
    bool m_statusAc;
    Passive* m_passivePtr;
};

#endif /* ACTIVE_H */

