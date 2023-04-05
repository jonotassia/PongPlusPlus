#include <stdexcept>

#include "paddle.h"
#include "game.h"


Paddle::Paddle(Player* player, float pos_x) {
	setPlayer(player);
	player->setPaddle(this);

	// Set x position and check if within window width
	if (pos_x > 0 || pos_x < WINDOW_WIDTH) {
		position_x = pos_x;
	}
	else {
		throw std::invalid_argument("X must be between 0 and the window's width");
	}
}
/*
Checks direction of paddle. If it has a direction, move it "speed" incremements in that direction.
Verifies that the paddle does not pass top or bottom boundary. If it does, set direction to kNone.
*/
void Paddle::Update() {
	switch (direction) {
		case Direction::kUp:
			if (checkBoundary(Direction::kUp)) {
				position_y += speed;
			}
		case Direction::kDown:
			if (checkBoundary(Direction::kDown)) {
				position_y -= speed;
			}
	}
}

/*
Checks that the paddle has not passed the boundary of the window using the following criteria:
	* 0 < position_y or position_y < WINDOW_HEIGHT, dependant on the direction passed as an argument
	* Position_y is handled appropriately based on position_y and its height
*/
bool Paddle::checkBoundary(Direction direction) {
	switch (direction) {
	// Check top boundary
	case Direction::kUp:
		if (position_y < WINDOW_HEIGHT) {
			return true;
		}
	// Check bottom boundary
	case Direction::kDown:
		if (position_y - height > 0) {
			return true;
		}
	}
	// If neither case is true, return false
	return false;
}