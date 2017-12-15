#ifndef CLUB_H
#define CLUB_H

#include "Item.h"

class Club: public Item {
public:
    Club();
    Club(const Club& orig);
    virtual ~Club();
    
    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;

private:

};

#endif /* CLUB_H */

