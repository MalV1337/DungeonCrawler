#ifndef MAIL_ARMOUR_H
#define MAIL_ARMOUR_H

#include "Item.h"

class Mail_Armour: public Item {
public:
    Mail_Armour();
    Mail_Armour(const Mail_Armour& orig);
    virtual ~Mail_Armour();

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
   
private:

};

#endif /* MAIL_ARMOUR_H */

