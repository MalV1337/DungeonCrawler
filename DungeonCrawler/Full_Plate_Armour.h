#ifndef FULL_PLATE_ARMOUR_H
#define FULL_PLATE_ARMOUR_H

#include "Item.h"

class Full_Plate_Armour: public Item {
public:
    Full_Plate_Armour();
    Full_Plate_Armour(const Full_Plate_Armour& orig);
    virtual ~Full_Plate_Armour();
    
    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;


private:

};

#endif /* FULL_PLATE_ARMOUR_H */

