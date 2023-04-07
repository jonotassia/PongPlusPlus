#include <stdexcept>

#include "paddle.h"
#include "game.h"
#include "ball.h"

Paddle::Paddle(Session* pSession, Player* player, float pos_x) {
	// Set Player
	setPlayer(player);
	player->setPaddle(this);
	
	// Set Session
	pSession_ = pSession;

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
				position_y -= speed;
				break;
			}
		case Direction::kDown:
			if (checkBoundary(Direction::kDown)) {
				position_y += speed;
				break;
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
		if (position_y > 0) {
			return true;
		}
		break;
	// Check bottom boundary
	case Direction::kDown:
		if (position_y + height < WINDOW_HEIGHT) {
			return true;
		}
		break;
	}
	// If neither case is true, return false
	return false;
}

/*
Catches the ball if it meets the following criteria:
	* Ball is within 2 pixels of the paddle in the x direction
	* Ball is between the top and bottom of the paddle in the y direction
*/
void Paddle::catchBall() {
	// Extracting data points for readability before conditional expressions
	float ball_x = pSession_->getBall()->position_x;
	float ball_y = pSession_->getBall()->position_y;
	auto player_num = this->getPlayer()->player_num;
	
	// Check boundaries against paddle one (with small leniency of 2 pixels in x direction), then catch ball.
	if (player_num == Player::PlayerNum::kOne) {
		if (ball_x < position_x + width + 2 && ball_y > position_y && ball_y < position_y + height) {
			pSession_->getBall()->ball_served = false;
			pPlayer_->serve_owner = true;
			ball_caught = true;
		}
	}
	// Check boundaries against paddle two (with small leniency of 2 pixels in x direction), then catch ball.
	else {
		if (ball_x < position_x - 2 && ball_y > position_y && ball_y < position_y + height) {
			pSession_->getBall()->ball_served = false;
			pPlayer_->serve_owner = true;
			ball_caught = true;
		}
	}
}

// Reset paddle directions
void Paddle::resetDirection() {
	this->direction = Direction::kNone;
}