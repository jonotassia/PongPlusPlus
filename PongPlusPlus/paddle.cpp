#include <stdexcept>

#include "paddle.h"
#include "game.h"

Paddle::Paddle(Player* player, float pos_x) {
	setPlayer(player);

	// Set x position and check if within window width
	if (pos_x > 0 || pos_x < WINDOW_WIDTH) {
		position_x = pos_x;
	}
	else {
		throw std::invalid_argument("X must be between 0 and the window's width");
	}
}

void Paddle::Update() {
	switch (direction_) {
		case Game::Direction::kUp:
			position_y += speed;
		case Game::Direction::kDown:
			position_y -= speed;
	}
}