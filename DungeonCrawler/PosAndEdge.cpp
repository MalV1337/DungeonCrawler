#include "PosAndEdge.h"

Position::Position() {
    reihe = 0;
    spalte = 0;
}

Position::Position(int x, int y) {
    reihe = x;
    spalte = y;
}

istream& operator>>(istream& inputstream, Position& pos) {
    char tmp;
    inputstream >> pos.reihe >> tmp >> pos.spalte;
    return inputstream;
}

ostream& operator<<(ostream& outputstream, const Position& pos) {
    outputstream << pos.reihe << "/" << pos.spalte;
    return outputstream;
}

bool Position::operator<(const Position& rechts) const{
    if (this->reihe < rechts.reihe)
        return true;
    if (this->spalte < rechts.spalte && this->reihe == rechts.reihe)
        return true;
    else
        return false;
}

bool Position::operator>(const Position& rechts) const{
    return (*this < rechts);
}

Position Position::operator-(const Position& rechts){
    return Position((this->reihe-rechts.reihe), (this->spalte-rechts.spalte));
}

Position Position::operator+(const Position& rechts){
    return Position((this->reihe+rechts.reihe), (this->spalte+rechts.spalte));
}

bool Position::operator!=(const Position& rhs) {
    return !((*this) == rhs);
}

bool operator==(const Position& lhs, const Position& rhs) {
    return (lhs.reihe == rhs.reihe && lhs.spalte == rhs.spalte);
}

Kante::Kante(Position pos1, Position pos2) {
    if (pos1 > pos2) {
        knoten1 = pos2;
        knoten2 = pos1;
    } else {
        knoten1 = pos1;
        knoten2 = pos2;
    }
    m_dist = numeric_limits<int>::max();
    m_visited = false;

}

bool Kante::operator<(const Kante& rechts) const {
    if(this->knoten1.reihe < rechts.knoten1.reihe)
        return true;
    if(this->knoten1.reihe == rechts.knoten1.reihe && this->knoten2.spalte < rechts.knoten2.spalte)
        return true;
    else
        return false;

}

bool Kante::operator>(const Kante& rechts) const{
    return (*this < rechts);
}


