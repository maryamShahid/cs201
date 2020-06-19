#ifndef __SIMPLE_TEAM_H
#define __SIMPLE_TEAM_H

#include <string>

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

private:
    string teamName;
    string teamColor;
    int teamYear;
};

#endif