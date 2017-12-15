#include "Full_Plate_Armour.h"

Full_Plate_Armour::Full_Plate_Armour() {
}

Full_Plate_Armour::Full_Plate_Armour(const Full_Plate_Armour& orig) {
}

Full_Plate_Armour::~Full_Plate_Armour() {
}

int Full_Plate_Armour::modifyStamina(int stamina) {
    return stamina + 6;
}

int Full_Plate_Armour::modifyStrength(int strength) {
    return strength - 2;
}
