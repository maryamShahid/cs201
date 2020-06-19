#include "Player.h"

Player::Player(const string playerName, const string position) {
    this->playerName = playerName;
    this->playerPosition = position;
}

void Player::operator=(const Player &right) {
    if (&right != this) {
        playerName = right.playerName;
        playerPosition = right.playerPosition;
    }
}

string Player::getPlayerName () const {
    return playerName;
}

void Player::setPlayerName(const string playerName) {
    this->playerName = playerName;
}

string Player::getPlayerPosition () const {
    return playerPosition;
}

void Player::setPlayerPosition (const string position) {
    this->playerPosition = position;
}