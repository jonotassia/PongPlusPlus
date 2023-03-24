#include <stdexcept>

#include "paddle.h"
#include "game.h"

Paddle::Paddle(Player* player, float pos_x) {
	setPlayer(player);

	if (pos_x > 0 || pos_x < WINDOW_WIDTH) {
		position_x = pos_x - this->width / 2;
	}
	else {
		throw std::invalid_argument("X must be between 0 and the window's width");
	}
}

void Paddle::movePaddle() {
	switch (direction_) {
		case Game::Direction::kUp:
			position_y += speed;
		case Game::Direction::kDown:
			position_y -= speed;
	}
}