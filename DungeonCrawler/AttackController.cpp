#include <memory>

#include "AttackController.h"
#include "DungeonMap.h"
#include "GameEngine.h"

AttackController::AttackController(Character* character, DungeonMap& map) : Controller(character), m_map(map) { //referenz
    Controller::setCharCon(character);
}

//AttackController::AttackController(const AttackController& orig) {
//}

AttackController::~AttackController() {
}

std::string AttackController::getControllerName() {
    return "AttackController";
}




int AttackController::move() {

    fovCharacter();

    if (m_lastPath.size() == 0)
        return 5;

    Position lp = m_map.findCharacter(getCharacterCon());
    Position dp = lp - m_lastPath[0];
    m_lastPath.erase(m_lastPath.begin());
    
    

        if (dp.reihe == -1 && dp.spalte == 1)
            return 1;
        else if (dp.reihe == -1 && dp.spalte == 0)
            return 2;
        else if (dp.reihe == -1 && dp.spalte == -1)
            return 3;
        else if (dp.reihe == 0 && dp.spalte == 1)
            return 4;
        else if (dp.reihe == 0 && dp.spalte == 0)
            return 5;
        else if (dp.reihe == 0 && dp.spalte == -1)
            return 6;
        else if (dp.reihe == 1 && dp.spalte == 1)
            return 7;
        else if (dp.reihe == 1 && dp.spalte == 0)
            return 8;
        else if (dp.reihe == 1 && dp.spalte == -1)
            return 9;
        else {
            cerr << "Old path is invalid.";
            m_lastPath.clear();
            return 5;
        }
}

void AttackController::fovCharacter() {
    vector<int> dim = m_map.getDimension();
    vector<Position> shortest, current;
    Position pos(0, 0);
    for (pos.reihe; pos.reihe < dim[0]; pos.reihe++) {
        for (pos.spalte; pos.spalte < dim[1]; pos.spalte++) {
            if (m_map.findTile(pos)->getCharacter() != nullptr && m_map.findTile(pos)->getCharacter() != Controller::getCharacterCon()) {
                if (m_map.hasLineOfSight(m_map.findCharacter(Controller::getCharacterCon()), pos)) {
                    current = m_map.getPathTo(m_map.findCharacter(Controller::getCharacterCon()), pos);
                    if (shortest.size() == 0 || (shortest.size() > current.size() && current.size() != 0)) {
                        shortest = current;
                    }
                }
            }
        }
        pos.spalte = 0;
    }
    if (shortest.size() != 0)
        m_lastPath = shortest;
}

Position AttackController::visibleCharCheck() {
    for (int i = 0; i < m_map.getReihe(); i++) {
        for (int j = 0; j < m_map.getSpalte(); j++) {
            if (m_map[i][j]->hasCharacter() &&
                    m_map[i][j]->getCharacter()->getController()->getControllerName() == "AttackController") {
                return m_map.findTile(m_map[i][j]);
            }
        }
    }
}

Position AttackController::enemyCharCheck() {
    for (int i = 0; i < m_map.getReihe(); i++) {
        for (int j = 0; j < m_map.getSpalte(); j++) {
            if (m_map[i][j]->hasCharacter() &&
                    m_map[i][j]->getCharacter()->getController()->getControllerName() != "AttackController") {
                return m_map.findTile(m_map[i][j]);
            }
        }
    }
}

