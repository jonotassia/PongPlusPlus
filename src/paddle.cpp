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

				// Make the ball "stick" to the paddle if it has been caught
				if (ball_caught) {
					pSession_->getBall()->position_y -= speed;
				}

				break;
			}
		case Direction::kDown:
			if (checkBoundary(Direction::kDown)) {
				position_y += speed;

				// Make the ball "stick" to the paddle if it has been caught
				if (ball_caught) {
					pSession_->getBall()->position_y += speed;
				}

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
	* Ball is within [contact leniency] pixels of the paddle in the x direction
	* Ball is between the top and bottom of the paddle in the y direction
If ball is not caught, the paddle will shrink by 10%.
*/
void Paddle::catchBall() {
	if (catches_remaining_ < 1) {
		return;
	}
	
	// Extracting data points for readability before conditional expressions
	Ball* ball = pSession_->getBall();
	float ball_x = ball->position_x;
	float ball_y = ball->position_y;
	auto player_num = this->getPlayer()->player_num;
	
	// Check boundaries against paddle one (with leniency of [contact leniency] pixels), then catch ball.
	if (player_num == Player::PlayerNum::kOne) {
		if (ball_x < position_x + width + CONTACT_LENIENCY 
				&& ball_x > position_x
				&& ball_y > position_y - CONTACT_LENIENCY 
				&& ball_y < position_y + height + CONTACT_LENIENCY) {
			
			this->activatePowerup();

			// Set ball location to the middle of the paddle
			ball->position_y = this->position_y + height / 2;
			ball->position_x = this->position_x + width + CONTACT_LENIENCY;

			// Reset ball x-velocity to ensure it serves correct direction
			if (ball->x_speed_ < 0) {
				ball->x_speed_ *= -1;
			}
		}
		shrinkPaddle(0.9);
	}
	// Check boundaries against paddle two (with leniency of [contact leniency] pixels), then catch ball.
	else {
		if (ball_x > position_x - CONTACT_LENIENCY 
				&& ball_x < position_x
				&& ball_y > position_y - CONTACT_LENIENCY
				&& ball_y < position_y + height + CONTACT_LENIENCY) {
			
			this->activatePowerup();

			// Set ball location to the middle of the paddle
			ball->position_y = this->position_y + height / 2;
			ball->position_x = this->position_x - CONTACT_LENIENCY;

			// Reset ball x-velocity to ensure it serves correct direction
			if (ball->x_speed_ > 0) {
				ball->x_speed_ *= -1;
			}
		}
		shrinkPaddle(0.9);
	}
}

/*
Responsible for controlling catch action of the paddle and the ball:
	* Sets the ball serve
	* Uses the session to set the active powerup
	* Sticks the ball to the middle of the paddle while waiting to serve
	* Decrements remaining catches
*/
void Paddle::activatePowerup() {
	// Handle ball serving
	pSession_->getBall()->ball_served = false;
	pPlayer_->serve_owner = true;
	ball_caught = true;

	// Activate powerup
	pSession_->activatePowerup(pPlayer_->selected_powerup, this);

	// Decrement catches remaining
	this->catches_remaining_--;
}

/*
Shrinks the paddle by [percent]. Primary use case is to punish users when they try to spam catch.
Minimum is set to 30% of max height.
*/
void Paddle::shrinkPaddle(float percent) {
	if (height > init_height * 0.3) {
		float reduction = this->height * (1 - percent);
		this->height -= reduction;
		this->position_y += reduction / 2;
	}
}

// Reset paddle directions
void Paddle::resetDirection() {
	this->direction = Direction::kNone;
}