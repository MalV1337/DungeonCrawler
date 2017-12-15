#include "Shield.h"

Shield::Shield() {
}

Shield::Shield(const Shield& orig) {
}

Shield::~Shield() {
}

int Shield::modifyStamina(int stamina) {
    return (stamina/100)*100;
}

int Shield::modifyStrength(int strength) {
    return strength - 1;
}

