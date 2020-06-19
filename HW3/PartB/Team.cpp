#include "Team.h"
#include <iostream>
#include<bits/stdc++.h>

Team::Team(const string tName, const string tColor, const int tYear) {
    teamName = tName;
    teamColor = tColor;
    teamYear = tYear;
    head = NULL;
}

Team::~Team() {
    if (head != NULL) {
        PlayerNode *curr = head;
        PlayerNode *next;
        while (curr != NULL) {
            next = curr-> next;
            delete curr;
            curr = next;
        }
    }
}

void Team::operator=(const Team &right) {
    if (&right != this) {
        teamName = right.teamName;
        teamColor = right.teamColor;
        teamYear = right.teamYear;
        if (right.head == NULL) {
            head = NULL;
        }
        else {
            head = new PlayerNode;
            head->p = right.head->p;
            PlayerNode *newPtr = head;
            for (PlayerNode *origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
                newPtr->next = new PlayerNode;
                newPtr = newPtr->next;
                newPtr->p = origPtr->p;
            }
            newPtr->next = NULL;
        }
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

void Team::addPlayer(const string pName, const string pPosition) {
    if (findPlayer(pName) != NULL)
        cout << "Player " << pName << " already exists in team " << teamName << endl;
    else if (head == NULL) {
        head = new PlayerNode;
        head->p.setPlayerName(pName);
        head->p.setPlayerPosition(pPosition);
        head->next = NULL;
    }
    else {
        PlayerNode *curr = head;
        while (curr->next != NULL) {
            curr = curr->next;
        }
        curr->next = new PlayerNode;
        curr = curr->next;
        curr->p.setPlayerName(pName);
        curr->p.setPlayerPosition(pPosition);
        curr->next = NULL;
    }
}

void Team::removePlayer(const string pName) {
    PlayerNode *playerToRemove = findPlayer(pName);
    if (playerToRemove == NULL)
        cout << "Player " << pName << " does not exist in the team" << endl;
    else {
        PlayerNode *prev = head;
        for (PlayerNode *curr = head->next; curr != NULL; curr = curr->next) {
            if (curr == playerToRemove) {
                prev->next = curr->next;
                delete curr;
            }
            else if (prev == playerToRemove) {
                head = prev->next;
                delete prev;
            }
            prev = prev->next;
        }
    }
}

void Team::displayPlayers() const {
    if (head == NULL) {
        cout << "--EMPTY--";
        return;
    }
    for (PlayerNode *curr = head; curr != NULL; curr = curr->next) {
        cout << curr->p.getPlayerName() << ", " << curr->p.getPlayerPosition() <<endl;
    }
}

bool Team::helperMethod(const string pName) {
    bool teamPresent = false;
    for (PlayerNode *curr = head; curr != NULL; curr = curr->next) {
        if (curr->p.getPlayerName() == pName) {
                cout << curr->p.getPlayerPosition() << ", " << teamName << ", " << teamColor << ", " << teamYear << endl;
                teamPresent = true;
            }
        }
    return teamPresent;
}

Team::PlayerNode* Team::findPlayer(const string pName) {
    string playerToFind = pName;
    string currentPlayerName = "";
    string temp = "";
    transform(playerToFind.begin(), playerToFind.end(), playerToFind.begin(), ::tolower);
    for (PlayerNode *curr = head; curr != NULL; curr = curr->next) {
        currentPlayerName = curr->p.getPlayerName();
        transform(currentPlayerName.begin(), currentPlayerName.end(), currentPlayerName.begin(), ::tolower);
        if (currentPlayerName == playerToFind) {
            return curr;
        }
    }
    return NULL;
}