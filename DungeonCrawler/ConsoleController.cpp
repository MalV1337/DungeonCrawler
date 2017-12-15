#include "ConsoleController.h"


ConsoleController::ConsoleController(Character* c): Controller(c) 
{
}

ConsoleController::ConsoleController(const ConsoleController& orig) {
}

ConsoleController::~ConsoleController() {
}

int ConsoleController::move() {
    int richtung = 0;
    cout << "In welche Richtung soll ihre Figur hin [1-9] ?\n";
    cin >> richtung;
    return richtung;
}

string ConsoleController::getControllerName() {
    return "ConsoleController";
}



