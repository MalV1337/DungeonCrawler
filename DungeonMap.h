#ifndef DUNGEONMAP_H
#define DUNGEONMAP_H

#include "Tile.h"
#include "Active.h"
#include "PosAndEdge.h"

class DungeonMap {
public:
    DungeonMap();
    DungeonMap(int height, int width);
    DungeonMap(int height, int width, const vector<string>& data);
    DungeonMap(int height, int width, const vector<string>& data, const vector<string>& polyTile);
    DungeonMap(const DungeonMap& orig);
    virtual ~DungeonMap();
    
    Tile** operator[](int index);
    friend ostream& operator<<(ostream& outputstream, const DungeonMap& map);
    DungeonMap& operator=(DungeonMap& right);
    friend void swapDm(DungeonMap& lDm, DungeonMap& rDm);
    
    int getReihe() const;
    int getSpalte() const;
    
    void place(Position pos, Character* c);
    Position findTile(Tile* t);
    Tile* findTile(Position pos);
    Position findCharacter(Character* c);
    void print() const;
    bool hasLineOfSight(Position from, Position to);
    void saveItems(ostream& outputstream);
    vector<Position> getPathTo(const Position from, const Position to);
    Position getMinDistance(set<Position> Q, map<Position,int> dist);
    vector<Position> getNeighbour(Position u);
    vector<int> getDimension();
    
private:
    Position m_pos;
    Tile*** m_dungeonMap;
};

#endif

