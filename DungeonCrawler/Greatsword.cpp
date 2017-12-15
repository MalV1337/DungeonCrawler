#include "Greatsword.h"

Greatsword::Greatsword() {
}

Greatsword::Greatsword(const Greatsword& orig) {
}

Greatsword::~Greatsword() {
}

int Greatsword::modifyStamina(int stamina) {
    return stamina - 1;
}

int Greatsword::modifyStrength(int strength) {
    return strength + 5;
}

