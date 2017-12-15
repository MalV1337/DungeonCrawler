#include "Gambeson.h"

Gambeson::Gambeson() {
}

Gambeson::Gambeson(const Gambeson& orig) {
}

Gambeson::~Gambeson() {
}

int Gambeson::modifyStamina(int stamina) {
    return stamina + 1;
}

int Gambeson::modifyStrength(int strength) {
    return 0;
}

