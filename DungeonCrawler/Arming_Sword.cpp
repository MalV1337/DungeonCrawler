#include "Arming_Sword.h"

Arming_Sword::Arming_Sword() {
}

Arming_Sword::Arming_Sword(const Arming_Sword& orig) {
}

Arming_Sword::~Arming_Sword() {
}

int Arming_Sword::modifyStamina(int stamina) {
    return 0;
}

int Arming_Sword::modifyStrength(int strength) {
    return strength + 3;
}

