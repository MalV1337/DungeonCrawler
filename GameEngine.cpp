#include "GameEngine.h"
#include "ConsoleController.h"
#include "StationaryController.h"
#include "Floor.h"
#include "Greatsword.h"
#include "AttackController.h"
#include "RapierAndDagger.h"
#include "Mail_Armour.h"
#include "Full_Plate_Armour.h"
#include "Club.h"
#include "Gambeson.h"
#include "Shield.h"

GameEngine::GameEngine() {
}

int GameEngine::amountofRounds = 0;

GameEngine::GameEngine(const int height, const int width,
        const vector<string>& data, const vector<string>& polyTile) :
m_dungeonMapGE(DungeonMap(height, width, data)) {
    connectTile(polyTile);
}

GameEngine::GameEngine(const GameEngine& orig) {
}

GameEngine::~GameEngine() {
    for (int i = 0; i < m_characterVec.size(); i++) {
        delete m_characterVec[i];
    }
    m_characterVec.erase(m_characterVec.begin(), m_characterVec.end());
    amountofRounds = 0;
}

DungeonMap GameEngine::getDungeonMapGE() const {
    return m_dungeonMapGE;
}

void GameEngine::connectTile(const vector<string>& polyTile) {
    for (int i = 0; i < polyTile.size(); i++) {
        string dungeonObj;
        istringstream iss(polyTile[i]);
        iss >> dungeonObj;
        if (dungeonObj == "Character") {
            char symbol;
            int strength;
            int stamina;
            Position pos;
            iss >> symbol >> strength >> stamina >> dungeonObj >> pos.reihe >> pos.spalte;
            Controller* controller = nullptr;
            if (dungeonObj == "ConsoleController")
                controller = new ConsoleController(nullptr);
            if (dungeonObj == "StationaryController")
                controller = new StationaryController(nullptr);
            if (dungeonObj == "AttackController")
                controller = new AttackController(nullptr, m_dungeonMapGE);
            m_characterVec.push_back(new Character(symbol, strength, stamina, controller)); // settet with this-Pointer  
            m_dungeonMapGE.place(pos, m_characterVec.back());
        } else if (dungeonObj == "Door") {
            string target;
            Passive* passiveTile;
            Active* activeTile;
            Position passiveObject;

            iss >> (passiveObject.reihe);
            iss >> passiveObject.spalte;

            passiveTile = dynamic_cast<Passive*> (m_dungeonMapGE.findTile(passiveObject));
            if (passiveTile == nullptr)
                throw runtime_error("Passive Tile nicht gefunden");


            while (!iss.eof()) {
                Position act;
                iss >> target;
                iss >> act.reihe;
                iss >> act.spalte;

                activeTile = dynamic_cast<Active*> (m_dungeonMapGE.findTile(act));
                if (activeTile != nullptr) {
                    activeTile->setPasPtr(passiveTile);
                } else {
                    throw runtime_error("Active Tile konnte nicht verbunden werden");
                }


                iss.ignore(1);

            }
        } else if (dungeonObj == "Item") {
            string target;
            Position pos;
            Item* item;
            iss >> target >> pos.reihe >> pos.spalte;
            Floor* tmpFloor;
            tmpFloor = dynamic_cast<Floor*> (m_dungeonMapGE.findTile(pos));
            if (tmpFloor == nullptr)
                throw runtime_error("Kann Item nicht platzieren");

            if (target == "Greatsword")
                item = new Greatsword;
            else if (target == "Club")
                item = new Club;
            else if (target == "Rapier")
                item = new RapierAndDagger;
            else if (target == "Gambeson")
                item = new Gambeson;
            else if (target == "MailArmour")
                item = new Mail_Armour;
            else if (target == "Shield")
                item = new Shield;
            else if (target == "FullPlateArmour")
                item = new Full_Plate_Armour;
            else
                throw runtime_error("Unbekanntes Item");

            tmpFloor->setItem(item);
        } else
            throw runtime_error("Verbindung konnte nicht aufgebaut werden");
    }
}

inline bool GameEngine::finished() {
    if (amountofRounds == 1337) {
        return true;
    }
    return false;
}

void GameEngine::print() {
    for (int i = 0; i < m_dungeonMapGE.getReihe(); i++) { //Kopiere Parameter zur dungeonMap 
        for (int j = 0; j < m_dungeonMapGE.getSpalte(); j++) {
            if (m_dungeonMapGE[i][j]->hasCharacter()) {
                cout << m_dungeonMapGE[i][j]->getCharacter()->getCharacter(); //Holt den Character* -> char für das Printen
            } else
                cout << m_dungeonMapGE[i][j]->getTileFromType();

        }
        cout << "\n";
    }
    cout << flush;
}

void GameEngine::clearCharacterVec() {
    for (int i = 0; i < m_characterVec.size(); i++) {
        delete m_characterVec[i];
    }
    m_characterVec.erase(m_characterVec.begin(), m_characterVec.end());
}

bool GameEngine::noPlayer() {
    for (int i = 0; i < m_characterVec.size(); i++)
        if (m_characterVec[i]->isAlive())
            return false;
    cout << endl << "Kein Spieler mehr übrig!" << endl << endl;
    return true;
}

void GameEngine::printCharInfo() const {
    for (int i = 0; i < m_characterVec.size(); i++) {
        cout << "Spieler " << i + 1 << endl;
        m_characterVec[i]->showInfo();
    }
    cout << endl;
}

void GameEngine::prinCharInfo(unsigned int playerNo) const {
    if (playerNo > m_characterVec.size())
        throw out_of_range("Spieler existiert nicht");
    cout << "Spieler " << playerNo << endl;
    m_characterVec[playerNo - 1]->showInfo();
    cout << endl;
}

void GameEngine::turn() {
    Position tmpPos;
    Tile* fromTile;
    Tile* toTile;
    unsigned int direction = 0;
    for (int i = 0; i < m_characterVec.size(); i++) {
        try {
            auto pos = m_dungeonMapGE.findCharacter(m_characterVec[i]);
        } 
        catch (const out_of_range& ia) {
            delete m_characterVec[i];
            m_characterVec.erase(m_characterVec.begin() + i);
            break;
        }
        print(m_dungeonMapGE.findCharacter(m_characterVec[i]));
        direction = m_characterVec[i]->move();
        tmpPos = m_dungeonMapGE.findCharacter(m_characterVec[i]);
        fromTile = m_dungeonMapGE.findTile(tmpPos);
        m_dungeonMapGE.place(tmpPos, m_characterVec[i]);
        switch (direction) {
            case 1: cout << "Der Spieler " << i + 1 << " ist nach unten links gelaufen.\n";
                tmpPos.reihe++;
                tmpPos.spalte--;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                fromTile->onLeave(toTile);
                break;
            case 2: cout << "Der Spieler " << i + 1 << " ist nach unten gelaufen.\n";
                tmpPos.reihe++;
                tmpPos.spalte;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                fromTile->onLeave(toTile);
                break;
            case 3: cout << "Der Spieler " << i + 1 << " ist nach unten rechts gelaufen.\n";
                tmpPos.reihe++;
                tmpPos.spalte++;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                fromTile->onLeave(toTile);
                break;
            case 4: cout << "Der Spieler " << i + 1 << " ist nach links gelaufen.\n";
                tmpPos.reihe;
                tmpPos.spalte--;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                fromTile->onLeave(toTile);

                break;
            case 5: cout << "Der Spieler " << i + 1 << " hat sich nicht bewegt.\n";
                tmpPos.reihe;
                tmpPos.spalte;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                break;
            case 6: cout << "Der Spieler " << i + 1 << " ist nach rechts gelaufen.\n";
                tmpPos.reihe;
                tmpPos.spalte++;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                fromTile->onLeave(toTile);
                break;
            case 7: cout << "Der Spieler " << i + 1 << " ist nach oben links gelaufen.\n";
                tmpPos.reihe--;
                tmpPos.spalte--;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                fromTile->onLeave(toTile);
                break;
            case 8: cout << "Der Spieler " << i + 1 << " ist nach oben gelaufen.\n";
                tmpPos.reihe--;
                tmpPos.spalte;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                fromTile->onLeave(toTile);
                break;
            case 9: cout << "Der Spieler " << i + 1 << " ist nach oben rechts gelaufen.\n";
                tmpPos.reihe--;
                tmpPos.spalte++;
                toTile = m_dungeonMapGE.findTile(tmpPos);
                fromTile->onLeave(toTile);
                break;
            case 0:
                amountofRounds = 1336;
                break;
            default: /*throw out_of_range("Ungueltige Eingabe");*/
                break;
        }
    }
}

void GameEngine::loadFromFile(string fileName) {
    ifstream save;
    save.open(fileName);
    if (save.good() == false) {
        cerr << "Datei konnte nicht geoeffnet werden!" << endl;
        return;
    }
    int hoehe, breite;
    save >> hoehe >> breite;
    vector<string> data;
    vector<string> links;
    string line;
    for (int i = 0; i < hoehe; i++) {
        getline(save, line);
        if (line != "")
            data.push_back(line);
        else
            i--;
    }
    do {
        getline(save, line);
        if (line != "")
            links.push_back(line);

    } while (save.good());


    save.close();


    clearCharacterVec();
    DungeonMap tmpDm = DungeonMap(hoehe, breite, data);

    m_dungeonMapGE = tmpDm;
    connectTile(links);
}

bool GameEngine::menue() {
    int eingabe = -1;
    int player = 0;

    string path;
    cout << "1. Starten\n" <<
            "2. Infos aller Spieler \n" <<
            "3. Infos eines beliebigen Spieler \n" <<
            "4. Aus Textdatei laden \n" <<
            "0. Beenden" << endl;
    cin >> eingabe;
    switch (eingabe) {
        case 1:
            amountofRounds = 0;
            run();
            break;
        case 2:
            printCharInfo();
            break;
        case 3:
            cout << "Welcher Spieler?" << endl;
            cin >> player;
            prinCharInfo(player);
            break;
        case 4:
            cout << "Spielpfad?" << endl;
            cin >> path;
            loadFromFile(path);
            break;
        case 0:
            cout << "Ende" << endl;
            return false;
            break;
        default:
            break;
    }
    return true;
}

void GameEngine::print(Position a) {
    for (int i = 0; i < m_dungeonMapGE.getReihe(); i++) {           //Kopiere Parameter zur dungeonMap 
        for (int j = 0; j < m_dungeonMapGE.getSpalte(); j++) {
            Position tmp;
            tmp.reihe = i;
            tmp.spalte = j;
            if (m_dungeonMapGE[i][j]->hasCharacter()) {
                cout << m_dungeonMapGE[i][j]->getCharacter()->getCharacter();
            } else if (m_dungeonMapGE.hasLineOfSight(a, tmp)) {
                cout << m_dungeonMapGE[i][j]->getTileFromType();    //Holt den Character* -> char für das Printen
            }
            else
                cout << ' ';


        }
        cout << "\n";
    }
    cout << flush;
}

void GameEngine::run() {
    while (!finished()) {
        turn();
        amountofRounds++;
    }
    for (int i = 0; i < m_characterVec.size(); i++) {
        print(m_dungeonMapGE.findCharacter(m_characterVec[i]));
    }

}
