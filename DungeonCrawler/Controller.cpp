#include "Controller.h"

Controller::Controller() {
}

Controller::Controller(Character* c) {
    m_charactControl = c;
}

Controller::Controller(const Controller& orig) {
}

Controller::~Controller() {
    m_charactControl = nullptr;
}

Character* Controller::getCharacterCon() const {
    return m_charactControl;
}

void Controller::setCharCon(Character* c) {
    m_charactControl = c;
}


