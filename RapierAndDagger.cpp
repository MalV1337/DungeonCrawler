#include "RapierAndDagger.h"

RapierAndDagger::RapierAndDagger() {
}

RapierAndDagger::RapierAndDagger(const RapierAndDagger& orig) {
}

RapierAndDagger::~RapierAndDagger() {
}

int RapierAndDagger::modifyStamina(int stamina) {
    return stamina + 1;
}

int RapierAndDagger::modifyStrength(int strength) {
    return strength + 2;
}

