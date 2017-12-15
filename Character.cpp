#include "Character.h"
#include "ConsoleController.h"
#include "Item.h"

Character::Character(char c, int strength, int stamina, Controller* controller):
m_character(c),m_strength(strength),m_stamina(stamina) {
    m_controller = controller;
    m_controller->setCharCon(this);      
    m_hitpoints = getMaxHP();  
}


Character::Character(const Character& orig) {
}

Character::~Character() {
    delete m_controller;
    for(int i = 0;i < m_itemVec.size();i++){
        delete m_itemVec[i];
    }
}

char Character::getCharacter() const {
    return m_character;
}

Controller* Character::getController() {
    return m_controller;
}

void Character::setController(Controller* control) {
    m_controller = control;
}

ostream& operator<<(ostream& outputstream, const Character& character) {
    outputstream << "Character " << " " << character.m_character << " " << character.m_strength << " " << character.m_stamina << " " << character.m_controller->getControllerName() << " ";
    return outputstream;
}

int Character::move() {
    if (m_controller == nullptr)
        return -1;
    return m_controller->move();
}

int Character::getMaxHP() const{
    return 20 + (getStamina()*5);
}

void Character::showInfo() const {
    cout << "Strength : " << getStrength() << endl
         << "Stamina : " << getStamina() << endl
         << "Hitpoints : " << m_hitpoints << " / " << getMaxHP() << "\n\n";
}

void Character::addItem(Item* itemObj) {
    
    m_itemVec.push_back(itemObj);
}

int Character::getStamina() const {
    int tmpBonus = m_stamina;
    for(int i = 0;i < m_itemVec.size();i++){
        tmpBonus += m_itemVec[i]->modifyStamina(m_stamina);
    }
    return tmpBonus;
}

int Character::getStrength() const {
    int tmpBonus = m_strength;
    for(int i = 0;i < m_itemVec.size();i++){
        tmpBonus += m_itemVec[i]->modifyStrength(m_strength);
    }
    return tmpBonus;
}


bool Character::hit(int damage){
    m_hitpoints = m_hitpoints - damage;
    if(m_hitpoints < 0)
        return true;
    else if(m_hitpoints > getMaxHP())
        m_hitpoints = getMaxHP();
    return false;
}

bool Character::isAlive() {
    if (dynamic_cast<ConsoleController*> (m_controller) != nullptr)
        return true;
    else
        return false;
}







