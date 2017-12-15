#include "StationaryController.h"

StationaryController::StationaryController(Character* c): Controller(c) {
}

StationaryController::StationaryController(const StationaryController& orig) {
}

StationaryController::~StationaryController() {
}

int StationaryController::move() {
    return 5;
}

string StationaryController::getControllerName() {
    return "StationaryController";
}



