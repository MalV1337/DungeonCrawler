#include "DungeonMap.h"
#include "Character.h"
#include "Wall.h"
#include "Floor.h"
#include "Door.h"
#include "Switch.h"
#include "Lever.h"
#include "Trap.h"
#include "GameEngine.h"

DungeonMap::DungeonMap() {

}

Tile** DungeonMap::operator[](int index) {
    return m_dungeonMap[index];
}

DungeonMap& DungeonMap::operator=(DungeonMap& right) {
    swapDm(*this, right);
    return *this;
}

ostream& operator<<(ostream& outputstream, const DungeonMap& map) {
    outputstream << map.m_pos.reihe << " " << map.m_pos.spalte << "\n";
    for (int i = 0; i < map.m_pos.reihe; i++) {
        for (int j = 0; j < map.m_pos.spalte; j++) {
            outputstream << map.m_dungeonMap[i][j]->save();
        }
        outputstream << "\n";
    }
    outputstream << "\n";
    
    return outputstream;
}

void swapDm(DungeonMap& lDm, DungeonMap& rDm) {
    std::swap(lDm.m_dungeonMap, rDm.m_dungeonMap);
    std::swap(lDm.m_pos, rDm.m_pos);
}

DungeonMap::DungeonMap(int reihe, int spalte) {
    m_pos.reihe = reihe;
    m_pos.spalte = spalte;
    m_dungeonMap = new Tile**[m_pos.reihe];
    for (int i = 0; i < m_pos.reihe; i++) {
        m_dungeonMap[i] = new Tile*[m_pos.spalte];
    }

    for (int i = 0; i < m_pos.reihe; i++) {
        for (int j = 0; j < m_pos.spalte; j++) {
            m_dungeonMap[i][j] = nullptr;
        }
    }
}

DungeonMap::DungeonMap(int reihe, int spalte, const vector<string>& data) {
    m_pos.reihe = reihe;
    m_pos.spalte = spalte;

    m_dungeonMap = new Tile**[m_pos.reihe];

    for (int row = 0; row < m_pos.reihe; row++) {
        string currentString = data[row];
        m_dungeonMap[row] = new Tile*[m_pos.spalte];
        for (int column = 0; column < m_pos.spalte; column++) {
            if (currentString[column] == '#') {
                m_dungeonMap[row][column] = new Wall;
            } else if (currentString[column] == '.') {
                m_dungeonMap[row][column] = new Floor;
            } else if (currentString[column] == 'X') {
                m_dungeonMap[row][column] = new Door;
            } else if (currentString[column] == 'S') {
                m_dungeonMap[row][column] = new Switch;
            } else if (currentString[column] == 'D') { //tmpDooPtr ist ein Passive* mit new Door
                m_dungeonMap[row][column] = new Door;
            } else if (currentString[column] == 'L') { //tmpDooPtr ist ein Passive* mit new Door
                m_dungeonMap[row][column] = new Lever;
            } else if (currentString[column] == 'T') { //tmpDooPtr ist ein Passive* mit new Door
                m_dungeonMap[row][column] = new Trap;
            }
        }
    }
}

DungeonMap::DungeonMap(const DungeonMap& orig) {
    m_pos.reihe = orig.m_pos.reihe;
    m_pos.spalte = orig.m_pos.spalte;

    m_dungeonMap = new Tile**[m_pos.reihe];
    for (int i = 0; i < m_pos.reihe; i++) {
        m_dungeonMap[i] = new Tile*[m_pos.spalte];
    }
    for (int i = 0; i < m_pos.reihe; i++) { //Kopiere Parameter zur dungeonMap 
        for (int j = 0; j < m_pos.spalte; j++) {
            m_dungeonMap[i][j] = new Tile(*orig.m_dungeonMap[i][j]);
        }
    }
}

DungeonMap::DungeonMap(int reihe, int spalte,
        const vector<string>& data, const vector<string>& DanS) {
    m_pos.reihe = reihe;
    m_pos.spalte = spalte;
    m_dungeonMap = new Tile**[m_pos.reihe];

    for (int row = 0; row < m_pos.reihe; row++) {
        string currentString = data[row];
        m_dungeonMap[row] = new Tile*[m_pos.spalte];
        for (int column = 0; column < m_pos.spalte; column++) {
            if (currentString[column] == '#') {
                m_dungeonMap[row][column] = new Wall;
            } else if (currentString[column] == '.') {
                m_dungeonMap[row][column] = new Floor;
            } else if (currentString[column] == 'X') {
                m_dungeonMap[row][column] = new Door;
            } else if (currentString[column] == 'S') {
                m_dungeonMap[row][column] = new Switch;
            } else if (currentString[column] == 'D') { //tmpDooPtr ist ein Passive* mit new Door
                m_dungeonMap[row][column] = new Door;
            } else if (currentString[column] == 'L') { //tmpDooPtr ist ein Passive* mit new Door
                m_dungeonMap[row][column] = new Lever;
            } else if (currentString[column] == 'T') { //tmpDooPtr ist ein Passive* mit new Door
                m_dungeonMap[row][column] = new Trap;
            }
        }
    }
}

int DungeonMap::getReihe() const {
    return m_pos.reihe;
}

int DungeonMap::getSpalte() const {
    return m_pos.spalte;
}

void DungeonMap::place(Position pos, Character* c) {
    if (pos.reihe > m_pos.reihe || pos.spalte > m_pos.spalte)
        throw out_of_range("Diese Reihe bzw. Spalte existiert nicht.");
    m_dungeonMap[pos.reihe][pos.spalte]->setCharacter(c); // Throw : Wenn Reihe/spalte nicht existiert
}

Position DungeonMap::findTile(Tile* t) {
    Position tmpPos;
    tmpPos.reihe = -1;
    tmpPos.spalte = -1;
    for (int i = 0; i < m_pos.reihe; i++) {
        for (int j = 0; j < m_pos.spalte; j++) {
            if (m_dungeonMap[i][j] == t) {
                tmpPos.reihe = i; // Pointer verglichen wird aber nicht benutzt
                tmpPos.spalte = j; //Throw: wenn Position nicht gefunden wird FIXED
                return tmpPos;
            }
        }
    }
    if (tmpPos.reihe == -1 && tmpPos.spalte == -1)
        throw out_of_range("Position wurde nicht gefunden !");
}

Tile* DungeonMap::findTile(Position pos) {
    Tile* tilePtr = nullptr;
    if ((pos.reihe > m_pos.reihe || pos.spalte > m_pos.spalte)
            || (pos.reihe < 0 || pos.spalte < 0))
        throw out_of_range("Diese Position existiert nicht.");
    tilePtr = m_dungeonMap[pos.reihe][pos.spalte]; //Throw:Wenn Position nicht existiert FIXED
    return tilePtr;
}

Position DungeonMap::findCharacter(Character* c) {
    Position tmpPos;
    tmpPos.reihe = -1;
    tmpPos.spalte = -1;
    for (int i = 0; i < m_pos.reihe; i++) {
        for (int j = 0; j < m_pos.spalte; j++) {
            if (m_dungeonMap[i][j]->getCharacter() == c) {// Throw:wenn keine Charactere existieren FIXED
                tmpPos.reihe = i;
                tmpPos.spalte = j;
                return tmpPos;
            }
        }
    }
    if (tmpPos.reihe == -1 && tmpPos.spalte == -1)
        throw out_of_range("Character wurde nicht gefunden!");
}

void DungeonMap::print() const {
    //    for (int i = 0; i < m_pos.reihe; i++) { //Kopiere Parameter zur dungeonMap 
    //        for (int j = 0; j < m_pos.spalte; j++) {
    //            if (m_dungeonMap[i][j]->hasCharacter()) {
    //                cout << '$';
    //            } else
    //                cout << m_dungeonMap[i][j]->getTileFromEnum();
    //
    //        }
    //        cout << "\n";
    //    }
    //    cout << flush;
}

bool DungeonMap::hasLineOfSight(Position from, Position to) {
    int playerX = from.reihe;
    int playerY = from.spalte;
    int targetX = to.reihe;
    int targetY = to.spalte;

    double x = targetX - playerX; // Bresenham Algorithmus
    double y = targetY - playerY;
    double len = sqrt((x * x) + (y * y));

    if (!len) // player tile is same as target tile
        return true;

    double unitX = x / len;
    double unitY = y / len;

    x = playerX;
    y = playerY;
    for (double i = 1; i < len; i += 1) {
        if (m_dungeonMap[static_cast<int> (x + 0.5)][static_cast<int> (y + 0.5)]->isTransparent() == false)//isTileAWall( (int)x, (int)y ) )
            return false;

        x += unitX;
        y += unitY;
    }

    return true;
}

void DungeonMap::saveItems(ostream& outputstream) {
    for (int i = 0; i < m_pos.reihe; i++) {
        for (int j = 0; j < m_pos.spalte; j++) {
            if (dynamic_cast<Floor*> (m_dungeonMap[i][j]) != nullptr) {
                if (dynamic_cast<Floor*> (m_dungeonMap[i][j])->getItem() != nullptr)
                    outputstream << dynamic_cast<Floor*> (m_dungeonMap[i][j])->getItem() << " " << i << "/" << j << endl;
            }
        }
    }
}

vector<Position> DungeonMap::getNeighbour(Position u) {
    vector<Position> tmpNeighbour;
    for (int i = -1; i<+1; i++) {
        for (int j = -1; j<+1; j++) {
            if (m_dungeonMap[u.reihe + i][u.spalte + j]->isWalkable()) {
                tmpNeighbour.push_back(Position(u.reihe + i, u.spalte + j));
            }
        }
    }
    return tmpNeighbour;
}

vector<Position> DungeonMap::getPathTo(const Position from, const Position to) {
    //https://en.wikipedia.org/wiki/Dijkstra%27s_algorithm#Pseudocode
    //http://gitta.info/Accessibiliti/de/html/Dijkstra_learningObject1.html

    vector<Position> pfad;
    set<Position> Q;
    map<Position, int> dist;
    map<Position, Position> prev;

    const int INTMAX = numeric_limits<int>::max();
    const Position undefinedPos(-1, -1);

    //Initialize all Container with infinte and undefined Position
    Position pos(0, 0);
    for (; pos.reihe < getReihe(); pos.reihe++) {
        for (; pos.spalte < getSpalte(); pos.spalte++) {
            if (m_dungeonMap[pos.reihe][pos.spalte]->isWalkable()) {
                dist.insert(pair<Position, int>(pos, INTMAX));
                prev.insert(pair<Position, Position>(pos, undefinedPos));
                Q.insert(pos);
            }
        }
        pos.spalte = 0;
    }
    dist[from] = 0;

    while (Q.size() != 0) {
        Position u = *Q.begin();
        int minDist = INTMAX;
        for (auto itQ = Q.cbegin(); itQ != Q.end(); itQ++) {
            if (dist[*itQ] < minDist) {
                minDist = dist[*itQ];
                u = *itQ;
            }
        }

        if (u == to)
            break;

        if (minDist == INTMAX)
            return pfad;

        Q.erase(u); // Erase u out of unvisited Nodes

        for (int i = -1; i <= 1; i++) {
            for (int j = -1; j <= 1; j++) {
                Position v = Position(u.reihe + i, u.spalte + j);
                try {
                    if (findTile(v)->isWalkable()) {                //Check whether v is walkable
                        int altDist = dist[u] + 1;                  //Line 17 - Calculate alternate distance DungeonCrawler always +1
                        if (altDist < dist[v]) {                    //Check whether alternate Distance is smaller than distance if Neighbour 
                            dist[v] = altDist;                      //Line 19 replace alternate distance with current distance of Neighbour
                            prev[v] = u;                            //Line 20 set previous Node of neighbour node to u
                        }
                    }                                               //neighbor v of u  where v is still in  
                }                catch (out_of_range& oa) {
                    cerr << oa.what() << endl;
                }
            }
        }
    }
    /*
         upper left     up   upper right
                    \   I   /
                     \  I  /
                      \ I /
     Neighbour left ----u----Neighbour right
                      / I \
                     /  I  \ 
                    /   I   \
          lower left  lower  lower right
     
     */
    auto currentPos = to;
    while (currentPos != from) {
        pfad.push_back(currentPos);
        currentPos = prev[currentPos];
    }
    reverse(pfad.begin(), pfad.end());
    return pfad;
}

vector<int> DungeonMap::getDimension() {
    return vector<int>{getReihe(), getSpalte()};
}

DungeonMap::~DungeonMap() {
    for (int i = 0; i < m_pos.reihe; i++) {
        for (int j = 0; j < m_pos.spalte; j++) {
            delete m_dungeonMap[i][j];
        }
        delete[] m_dungeonMap[i];
    }
    delete[] m_dungeonMap;
}



