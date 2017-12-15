#ifndef ITEM_H
#define ITEM_H

#include "Character.h"


class Item {
public:
    Item();
    Item(const Item& orig);
    char getItemChar() const;
    virtual ~Item();
    virtual int modifyStrength(int strength);
    virtual int modifyStamina(int stamina);
    
private:
    char m_itemChar;
};

#endif /* ITEM_H */

