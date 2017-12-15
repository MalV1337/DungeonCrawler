#ifndef STATIONARYCONTROLLER_H
#define STATIONARYCONTROLLER_H

#include "Controller.h"


class StationaryController: public Controller {
public:
    StationaryController(Character* c);
    StationaryController(const StationaryController& orig);
    virtual ~StationaryController();
    int move() override;
    string getControllerName() override;


private:

};

#endif /* STATIONARYCONTROLLER_H */

