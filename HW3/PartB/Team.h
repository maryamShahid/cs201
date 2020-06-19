#ifndef __TEAM_H
#define __TEAM_H
#include <string>
#include "Player.h"
using namespace std;

class Team {
public:
    Team(const string tName = "", const string tColor = "", const int tYear = 0);
    ~Team();
    void operator=(const Team &t);
    string getTeamName();
    string getTeamColor();
    int getTeamYear();
    void setTeamName(const string tName);
    void setTeamColor(const string tColor);
    void setTeamYear(const int tYear);
    void addPlayer(const string pName, const string pPosition);
    void removePlayer(const string pName);
    void displayPlayers() const;
    bool helperMethod(const string pName);

private:
    struct PlayerNode {
        Player p;
        PlayerNode *next;
    };
    PlayerNode *head;
    PlayerNode *findPlayer(const string pName);

    string teamName;
    string teamColor;
    int teamYear;
};

#endif