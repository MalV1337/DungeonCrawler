#include "Mail_Armour.h"

Mail_Armour::Mail_Armour() {
}

Mail_Armour::Mail_Armour(const Mail_Armour& orig) {
}

Mail_Armour::~Mail_Armour() {
}

int Mail_Armour::modifyStamina(int stamina) {
    return stamina + 3;
}

int Mail_Armour::modifyStrength(int strength) {
    return 0;
}
