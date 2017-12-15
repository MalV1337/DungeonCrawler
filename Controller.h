#ifndef CONTROLLER_H
#define CONTROLLER_H

#include "Character.h"

class Controller {
public:
    Controller();
    Controller(Character* c);
    Controller(const Controller& orig);
    virtual ~Controller();
    
    Character* getCharacterCon() const;
    void setCharCon(Character* c);
    virtual string getControllerName()=0;
    virtual int move()=0;
protected:
    Character* m_charactControl;
};

#endif /* CONTROLLER_H */

