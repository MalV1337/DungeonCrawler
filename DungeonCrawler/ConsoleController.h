#ifndef CONSOLECONTROLLER_H
#define CONSOLECONTROLLER_H

#include "Controller.h"

class ConsoleController: public Controller {
public:
    ConsoleController(Character* c);
    ConsoleController(const ConsoleController& orig);
    virtual ~ConsoleController();
    
    string getControllerName() override;
    int move() override;


private:

};

#endif /* CONSOLECONTROLLER_H */

