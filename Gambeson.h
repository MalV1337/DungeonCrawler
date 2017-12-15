#ifndef GAMBESON_H
#define GAMBESON_H

#include "Item.h"

class Gambeson: public Item {
public:
    Gambeson();
    Gambeson(const Gambeson& orig);
    virtual ~Gambeson();
    
    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;

private:

};

#endif /* GAMBESON_H */

