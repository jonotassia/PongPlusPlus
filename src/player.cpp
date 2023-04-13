#include "player.h"

Player::Player(PlayerNum num) : player_num(num) {
	loadPlayerStats();
}

Player::~Player() {
	savePlayerStats();
}

void Player::savePlayerStats() {
	// TODO: Save player stats to file
}

void Player::loadPlayerStats() {
	// TODO: Load player stats from file
}