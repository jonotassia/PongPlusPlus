#include <cmath>

#include "paddle.h"
#include "ball.h"
#include "definitions.h"
#include "player.h"
#include "game.h"

Ball::Ball(Session* pSession) {
	pSession_ = pSession;
}

/*
Moves the ball, taking into consideration ball speed, potential direction changes from contact, and winning points
*/
void Ball::Update() {
	// Freeze the ball as long as it is not served
	if (ball_served) {
		// Handle powerups if trajectory impacted
		switch (pSession_->active_powerup) {
			case PowerUps::kConfusion:
				transformWaveMovement();
				break;
			default:
				position_x += x_speed_;
				position_y += y_speed_;
				break;
		}

		// Check collisions and winning positions, short circuit if one found
		if (checkContact(pSession_->getPaddleOne())) {
			return;
		}
		else if (checkContact(pSession_->getPaddleTwo())) {
			return;
		}
	}
}

/*
Checks if the ball should deflect from a wall or paddle using the following logic:
	* Ball is greater than WINDOW_HEIGHT
	* Ball is less than or equal to WINDOW_HEIGHT
	* Ball has not contacted a paddle
Short circuits if any contacts
*/
bool Ball::checkContact(Paddle* paddle) {
	// Check against top and bottom walls for bounces, short circuit if any contacts
	if (position_y <= 0 || position_y >= WINDOW_HEIGHT) {
		y_speed_ -= 2 * y_speed_;
		playWallBounce();
		return true;
	}
	// Check for collision against a paddle. Short circuit if paddle contacted to save processing
	else if (deflectFromPaddle(paddle)) {
		playPaddleHit();
		return true;
	}
	return false;
}

/*
Checks if the ball should deflect from a paddle using the following logic:
	* Ball is between y_max and y_min
	* If paddle one, ball is greater than x_max
	* If paddle two, ball is less than x_min
*/
bool Ball::deflectFromPaddle(Paddle* paddle) {
	// Calculate paddle boundaries
	float paddle_y_min = paddle->position_y;
	float paddle_y_max = paddle->position_y + paddle->height;

	// TODO: Optimize these checks so that we don't have to test separately for kOne and kTwo
	if (paddle->getPlayer()->player_num == Player::PlayerNum::kOne) {
		// Check boundaries against paddle one, then inverse x-speed
		float paddle_x_lim = paddle->position_x + paddle->width;

		if (position_y >= paddle_y_min && position_y <= paddle_y_max && position_x <= paddle_x_lim) {
			// Reverse speed and speed up
			x_speed_ -= 2 * x_speed_;
			speedBallUp(0.05);
			return true;
		}

		// If contacted by an ice ball, drop paddle speed
		if (pSession_->active_powerup == PowerUps::kIce) {
			paddle->speed *= 0.80;
		}

	}
	else {
		float paddle_x_lim = paddle->position_x;
		// Check boundaries against paddle two, then inverse x-speed
		if (position_y >= paddle_y_min && position_y <= paddle_y_max && position_x >= paddle_x_lim) {
			// Reverse speed and speed up
			x_speed_ -= 2 * x_speed_;
			speedBallUp(0.05);
			return true;
		}

		// If contacted by an ice ball, drop paddle speed
		if (pSession_->active_powerup == PowerUps::kIce) {
			paddle->speed *= 0.80;
		}
	}
	return false;
}

/*
Checks that the ball has passed a paddle without contact using the following logic:
	* Ball is less than x_min for paddle one
	* Ball is greater than x_max for paddle two
Assumes contact is always checked first!
*/
bool Ball::checkWinningPosition(Paddle* paddle) {
	// TODO: Optimize these checks so that we don't have to test separately for kOne and kTwo
	if (paddle->getPlayer()->player_num == Player::PlayerNum::kOne) {
		// Check boundaries against paddle one, then inverse x-speed
		if (position_x <= 0) {
			return true;
		}
	}
	else {
		float paddle_x_lim = paddle->position_x + paddle->width;
		// Check boundaries against paddle two, then inverse x-speed
		if (position_x >= WINDOW_WIDTH) {
			return true;
		}
	}
	return false;
}

/*
Sets the ball served flag to true, which will begin ball movement. 
Typically controlled by SPACE BAR for player 1 and ENTER for player 2.
*/
void Ball::serveBall() {
	// Reverse the direction of x speed if serve owner is paddle 2.
	if (pSession_->getPaddleTwo()->getPlayer()->serve_owner) {
		x_speed_ *= -1;
	}

	// Handle serve based on active powerup (if powerup is serve-centric)
	switch (pSession_->active_powerup) {
		case PowerUps::kFire:
			// Double ball speed
			this->x_speed_ *= 2;
			ball_served = true;
			break;
		default:
			// Normal serve
			ball_served = true;
			break;
	}

	// If ball was caught by either paddle, set the flag to false
	pSession_->getPaddleOne()->ball_caught = false;
	pSession_->getPaddleTwo()->ball_caught = false;

	// Set the serve owner to false for both paddles
	pSession_->getPaddleOne()->getPlayer()->serve_owner = false;
	pSession_->getPaddleTwo()->getPlayer()->serve_owner = false;
}

// Speeds ball up by a set increment
void Ball::speedBallUp(float increment) {
	if (x_speed_ > 0) {
		x_speed_ += increment;
	}
	else {
		x_speed_ -= increment;
	}
}

/*
Runs a small audio files when ball hits a wall
*/
void Ball::playWallBounce() {
	// TODO: Play wav file for wall bounce audio
}

/*
Runs a small audio files when ball hits a paddle
*/
void Ball::playPaddleHit() {
	// TODO: Play wav file for wall bounce audio
}

void Ball::transformWaveMovement() {
	double dir = atan2(y_speed_, x_speed_);

	position_x = position_x + cos(dir) * x_speed_;
	position_y = position_y + sin(dir) * y_speed_;

	const float deviation = sin(x_speed_ * M_PI / wave_period) * wave_amplitude;

	position_x += sin(dir) * deviation;
	position_y -= cos(dir) * deviation;
}
