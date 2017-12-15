/*
 * To change this license header, choose License Headers in Project Properties.
 * To change this template file, choose Tools | Templates
 * and open the template in the editor.
 */

/* 
 * File:   AttackController.h
 * Author: Malke
 *
 * Created on 14. Juni 2017, 11:52
 */

#ifndef ATTACKCONTROLLER_H
#define ATTACKCONTROLLER_H

#include "Controller.h"
#include "DungeonMap.h"
#include "GameEngine.h"

class AttackController : public Controller{
public:
    AttackController(Character* character, DungeonMap& map);
    virtual ~AttackController();
    int move() override;
    string getControllerName() override;
    
private:
    void fovCharacter();
    Position visibleCharCheck();
    Position enemyCharCheck();
    AttackController(const AttackController& orig);
    DungeonMap& m_map; //referenz
    vector<Position> m_lastPath;
};

#endif /* ATTACKCONTROLLER_H */

