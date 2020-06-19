#include "SimpleTeam.h"

Team::Team(const string tName, const string tColor, const int tYear) {
    teamName = tName;
    teamColor = tColor;
    teamYear = tYear;
}

Team::~Team() {
}

void Team::operator=(const Team &right) {
    if (&right != this) {
        teamName = right.teamName;
        teamColor = right.teamColor;
        teamYear = right.teamYear;
    }
}

string Team::getTeamName() {
    return teamName;
}

string Team::getTeamColor() {
    return teamColor;
}

int Team::getTeamYear() {
    return teamYear;
}

void Team::setTeamName(const string tName) {
    teamName = tName;
}

void Team::setTeamColor(const string tColor) {
    teamColor = tColor;
}

void Team::setTeamYear(const int tYear) {
    teamYear = tYear;
}
