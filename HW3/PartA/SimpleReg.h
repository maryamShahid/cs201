#ifndef __SIMPLE_REG_H
#define __SIMPLE_REG_H
#include <string>
using namespace std;
#include "SimpleTeam.h"
class SimpleReg {
public:
    SimpleReg();
    ~SimpleReg();
    void addTeam(const string tName, const string tColor, const int tyear);
    void removeTeam(const string teamName);
    void displayAllTeams() const;
private:
    struct Node {
        Team t;
        Node *next;
    };
    Node *head;
    int teamCount;
    Node *findTeam(const string teamName) const;
};

#endif

