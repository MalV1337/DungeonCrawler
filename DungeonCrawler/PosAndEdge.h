#ifndef POSANDEDGE_H
#define POSANDEDGE_H

#include "Tile.h"

struct Position {    
    Position();
    Position(int x, int y);
    
    int reihe;
    int spalte;

    friend bool operator==(const Position& lhs,const Position& rhs);
    bool operator!=(const Position& rhs);
    friend istream& operator>>(istream& inputstream, Position& pos);
    friend ostream& operator<<(ostream& outputstream, const Position& pos);
    bool operator<(const Position& rechts)const ;
    bool operator>(const Position& rechts) const;
    Position operator-(const Position& rechts);
    Position operator+(const Position& rechts);
};



struct Kante{ //for alternative Nodes Implementation 
    
    Position knoten1, knoten2;
    int m_dist;
    bool m_visited;
    Kante(Position pos1, Position pos2);
    
    bool operator<( const Kante& rechts) const;
    bool operator>(const Kante& rechts) const ;
    
};

#endif /* POSANDEDGE_H */

