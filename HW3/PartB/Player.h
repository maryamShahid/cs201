#ifndef __PLAYER_H
#define __PLAYER_H
#include <string>
using namespace std;

class Player {
public:
    Player(const string playerName = "", const string playerPosition = "");
    void operator=(const Player &p);
    string getPlayerName () const;
    void setPlayerName(const string playerName);
    string getPlayerPosition () const;
    void setPlayerPosition (const string position);
private:
    string playerName;
    string playerPosition;
};

#endif