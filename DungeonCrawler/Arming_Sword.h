#ifndef ARMING_SWORD_H
#define ARMING_SWORD_H

#include "Item.h"


class Arming_Sword: public Item {
public:
    Arming_Sword();
    Arming_Sword(const Arming_Sword& orig);
    virtual ~Arming_Sword();
    
    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;

private:

};

#endif /* ARMING_SWORD_H */

