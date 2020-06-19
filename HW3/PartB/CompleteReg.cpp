#include <iostream>
#include<bits/stdc++.h>
#include "CompleteReg.h"


CompleteReg::CompleteReg() {
    head = NULL;
    teamCount = 0;
}

CompleteReg::CompleteReg(const CompleteReg &systemToCopy) {
    teamCount = systemToCopy.teamCount;
    if (systemToCopy.head == NULL) {
        head = NULL;
    }
    else {
        head = new Node;
        head->t = systemToCopy.head->t;
        Node *newPtr = head;
        for (Node *origPtr = systemToCopy.head->next; origPtr != NULL; origPtr = origPtr->next) {
            newPtr->next = new Node;
            newPtr = newPtr->next;
            newPtr->t = origPtr->t;
        }
        newPtr->next = NULL;
    }
}

CompleteReg::~CompleteReg() {
    if (head != NULL) {
        Node* current = head;
        Node* next;
        while (current != NULL) {
            next = current->next;
            delete current;
            current = next;
        }
    }
}

CompleteReg& CompleteReg::operator=(const CompleteReg &right) {
    if (&right != this) {
        teamCount = right.teamCount;
        if (right.head == NULL) {
            head = NULL;
        } else {
            head = new Node;
            head->t = right.head->t;
            Node *newPtr = head;
            for (Node *origPtr = right.head->next; origPtr != NULL; origPtr = origPtr->next) {
                newPtr->next = new Node;
                newPtr = newPtr->next;
                newPtr->t = origPtr->t;
            }
            newPtr->next = NULL;
        }
    }
}

Team& CompleteReg::operator[](const int index) {
    Node *curr = head;
    for (int i = 0; i < index; i++) {
        curr = curr->next;
    }
    return curr->t;
}

void CompleteReg::addTeam(const string tName, const string tColor, const int tYear) {
    if (findTeam(tName) != NULL) {
        cout << "Team " << tName << " already exists in the system" << endl;
    }
    else if (tYear >= 2020)
        cout << "Team " << tName << " cannot be founded in the future" << endl;
    else if (tYear <= 1800)
        cout << "Team " << tName << " cannot be founded before 1800" << endl;
    else if (head == NULL) {
        head = new Node;
        head->t.setTeamName(tName);
        head->t.setTeamColor(tColor);
        head->t.setTeamYear(tYear);
        head->next = NULL;
        teamCount++;
    }
    else {
        Node* curr = head;
        while (curr->next != NULL){
            curr = curr->next;
        }
        curr->next = new Node;
        curr = curr->next;
        curr->t.setTeamName(tName);
        curr->t.setTeamColor(tColor);
        curr->t.setTeamYear(tYear);
        curr->next = NULL;
        teamCount++;
    }
}

void CompleteReg::removeTeam(const string teamName) {
    if (findTeam(teamName) == NULL) {
        cout << "Team " << teamName << " does not exist in the system" << endl;
    }
    else {
        Node* ptrToRemove = findTeam(teamName);
        Node* prev = head;
        if ((prev->next == NULL) && (prev == ptrToRemove)) {
            delete prev;
            head = NULL;
        }
        else {
            for (Node *curr = head->next; curr != NULL; curr = curr->next) {
                if (curr == ptrToRemove) {
                    Node* temp = curr->next;
                    prev->next = temp;
                    delete curr;
                }
                else if (prev == ptrToRemove) {
                    Node* temp = prev->next;
                    head = temp;
                    delete prev;
                }
                prev = prev->next;
            }
            teamCount--;
        }
    }
}

void CompleteReg::displayAllTeams() const {
    if (head == NULL) {
        cout << "--EMPTY--" << endl;
    } else {
        for (Node *curr = head; curr != NULL; curr = curr->next) {
            cout << curr->t.getTeamName() << ", " << curr->t.getTeamColor() << ", " << curr->t.getTeamYear()  << endl;
        }
    }
}

void CompleteReg::addPlayer(const string tName, const string pName, const string pPosition) {
    Node *teamToAddPlayerTo = findTeam(tName);
    if (teamToAddPlayerTo == NULL)
        cout << "Player " << pName << " not added because team " << tName << " does not exist in the system" << endl;
    else
        teamToAddPlayerTo->t.addPlayer(pName, pPosition);
}

void CompleteReg::removePlayer(const string teamName, const string playerName) {
    Node *teamToRemoveFrom = findTeam(teamName);
    if (teamToRemoveFrom == NULL)
        cout << "Player " << playerName << " not removed because team " << teamName << " does not exist in the system" << endl;
    else
        teamToRemoveFrom->t.removePlayer(playerName);
}

void CompleteReg::displayTeam(const string teamName) const {
    Node *team = findTeam(teamName);
    if (team == NULL)
        cout << "--EMPTY--" << endl;
    else {
        cout << team->t.getTeamName() << ", " << team->t.getTeamColor() << ", " << team->t.getTeamYear() << endl;
        team->t.displayPlayers();
    }
}

void CompleteReg::displayPlayer(const string playerName) const {
    cout << playerName << endl;
    bool hasTeams = false;
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        if (curr->t.helperMethod(playerName)) {
            hasTeams = true;
        }
        else {
            hasTeams = false;
        }
    }
    if (!hasTeams) {
        cout << "--EMPTY--" << endl;
    }
}

CompleteReg::Node * CompleteReg::findTeam(const string tName) const {
    string teamNameToFind = tName;
    string currentTeamName = "";
    string temp = "";
    transform(teamNameToFind.begin(), teamNameToFind.end(), teamNameToFind.begin(), ::tolower);
    for (Node *curr = head; curr != NULL; curr = curr->next) {
        currentTeamName = curr->t.getTeamName();
        transform(currentTeamName.begin(), currentTeamName.end(), currentTeamName.begin(), ::tolower);
        if (currentTeamName == teamNameToFind) {
            return curr;
        }
    }
    return NULL;
}