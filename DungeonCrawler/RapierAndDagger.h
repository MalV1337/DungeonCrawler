#ifndef RAPIERANDDAGGER_H
#define RAPIERANDDAGGER_H

#include "Item.h"

class RapierAndDagger: public Item {
public:
    RapierAndDagger();
    RapierAndDagger(const RapierAndDagger& orig);
    virtual ~RapierAndDagger();

    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;
    
private:

};

#endif /* RAPIERANDDAGGER_H */

