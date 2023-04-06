#include "ball.h"
#include "definitions.h"
#include "paddle.h"
#include "player.h"

Ball::Ball(Paddle* paddle_one, Paddle* paddle_two) {
	pPaddleOne_ = paddle_one;
	pPaddleTwo_ = paddle_two;
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
			x_speed_ -= 2 * x_speed_;
			return true;
		}
	}
	else {
		float paddle_x_lim = paddle->position_x;
		// Check boundaries against paddle two, then inverse x-speed
		if (position_y >= paddle_y_min && position_y <= paddle_y_max && position_x >= paddle_x_lim) {
			x_speed_ -= 2 * x_speed_;
			return true;
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
Moves the ball, taking into consideration ball speed, potential direction changes from contact, and winning points
*/
void Ball::Update() {
	if (ball_served) {
		position_x += x_speed_;
		position_y += y_speed_;

		// Check collisions and winning positions, short circuit if one found
		if (checkContact(pPaddleOne_)) {
			return;
		}
		else if (checkContact(pPaddleTwo_)) {
			return;
		}
	}
}

/*
Sets the ball served flag to true, which will begin ball movement. 
Typically controlled by SPACE BAR for player 1 and ENTER for player 2.
*/
void Ball::serveBall() {
	ball_served = true;
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


