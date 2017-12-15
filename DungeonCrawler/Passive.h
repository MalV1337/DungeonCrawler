#ifndef PASSIVE_H
#define PASSIVE_H

#include "Tile.h"

class Passive: public Tile {
public:
    Passive();
    Passive(const Passive& orig);
    virtual ~Passive();
    
    virtual bool getPasStatus() const;
    virtual void setPasStatus(bool state);
    virtual Passive* getPasObj();
    
protected:
    bool m_statusPas;
};

#endif /* PASSIVE_H */
