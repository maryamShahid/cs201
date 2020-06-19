#include <iostream>
#include<bits/stdc++.h>
#include "SimpleReg.h"

SimpleReg::SimpleReg() {
    head = NULL;
    teamCount = 0;
}

SimpleReg::~SimpleReg() {
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

void SimpleReg::addTeam(const string tName, const string tColor, const int tYear) {
    if (findTeam(tName) != NULL) {
        cout << "Team " << tName << " already exists" << endl;
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

void SimpleReg::removeTeam(const string teamName) {
    if (findTeam(teamName) == NULL) {
        cout << "Team " << teamName << " does not exist" << endl;
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

void SimpleReg::displayAllTeams() const {
    if (head == NULL) {
        cout << "--EMPTY--" << endl;
    } else {
        for (Node *curr = head; curr != NULL; curr = curr->next) {
            cout << curr->t.getTeamName() << ", " << curr->t.getTeamColor() << ", " << curr->t.getTeamYear()  << endl;
            }
        }
}

SimpleReg::Node * SimpleReg::findTeam(const string tName) const {
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