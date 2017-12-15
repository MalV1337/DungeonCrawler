#ifndef SHIELD_H
#define SHIELD_H

#include "Item.h"

class Shield: public Item {
public:
    Shield();
    Shield(const Shield& orig);
    virtual ~Shield();

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
  
private:

};

#endif /* SHIELD_H */

