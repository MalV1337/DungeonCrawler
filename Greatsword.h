#ifndef GREATSWORD_H
#define GREATSWORD_H

#include "Item.h"


class Greatsword: public Item {
public:
    Greatsword();
    Greatsword(const Greatsword& orig);
    virtual ~Greatsword();
    
    int modifyStamina(int stamina) override;
    int modifyStrength(int strength) override;

private:

};

#endif /* GREATSWORD_H */

