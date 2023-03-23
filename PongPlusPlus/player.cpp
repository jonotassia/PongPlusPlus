#include "player.h"

Player::Player(PlayerNum num) : player_num(num) {
	loadPlayerStats();
}

Player::~Player() {
	savePlayerStats();
}