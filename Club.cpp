#include "Club.h"

Club::Club() {
}

Club::Club(const Club& orig) {
}

Club::~Club() {
}

int Club::modifyStamina(int stamina) {
    return 0;
}

int Club::modifyStrength(int strength) {
    return (strength/100)*50;
}

