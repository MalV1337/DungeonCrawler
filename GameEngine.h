#ifndef GAMEENGINE_H
#define GAMEENGINE_H

#include "Character.h"

class GameEngine {
public:
    GameEngine();
    GameEngine(const int height, const int width, const vector<string>& data, const vector<string>& polyTile);
    GameEngine(const GameEngine& orig);
    virtual ~GameEngine();
    
    DungeonMap getDungeonMapGE() const;
    void clearCharacterVec();
    inline bool finished();
    void printCharInfo() const;
    inline void print(); //kann nicht const gesetzt werden
    inline void print(Position a);
    void prinCharInfo(unsigned int playerNo) const;
    void loadFromFile(string fileName);
    void connectTile(const vector<string>& polyTile);
    bool noPlayer();
    bool menue();
    void turn();
    void run();

private:
    vector<Character*> m_characterVec;
    DungeonMap m_dungeonMapGE;
    static int amountofRounds;
};

#endif /* GAMEENGINE_H */

