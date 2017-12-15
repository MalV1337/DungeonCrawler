#include "Item.h"
#include "Active.h"

Item::Item():
m_itemChar('*')
{
}

Item::Item(const Item& orig) {
}

Item::~Item() {
}

char Item::getItemChar() const {
    return m_itemChar;
}


int Item::modifyStamina(int stamina) {
    return 0;
}

int Item::modifyStrength(int strength) {
    return 0;
}

