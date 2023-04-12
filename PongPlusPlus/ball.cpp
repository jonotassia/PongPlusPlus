#include <cmath>

#include "paddle.h"
#include "ball.h"
#include "definitions.h"
#include "player.h"
#include "game.h"

Ball::Ball(Session* pSession) {
	pSession_ = pSession;

	// Handle serve direction based on serve owner
	x_speed_ = (pSession_->getPaddleOne()->getPlayer()->serve_owner) ? 0.5 : -0.5;
}

/*
Moves the ball, taking into consideration ball speed, potential direction changes from contact, and powerups
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

		// Check collisions and winning positions
		ContactEntity contact = checkContact();

		// If the active powerup is ConfuseBall, set wave parameters based on contact point
		if (pSession_->active_powerup == PowerUps::kConfusion) {
			switch (contact) {
				case ContactEntity::kBottom:
					wave_distance = 0;
					wave_init_x = position_x;
					wave_init_y = position_y;
				case ContactEntity::kTop:
					wave_distance = 0;
					wave_init_x = position_x;
					wave_init_y = position_y;
				case ContactEntity::kPaddleOne:
					wave_distance = 0;
					wave_init_x = position_x;
					wave_init_y = position_y;
				case ContactEntity::kPaddleTwo:
					wave_distance = 0;
					wave_init_x = position_x;
					wave_init_y = position_y;
				default:
					break;
			}
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
Ball::ContactEntity Ball::checkContact() {
	// Check against top and bottom walls for bounces, short circuit if any contacts
	if (position_y <= 0)  {
		y_speed_ *= -1;
		playWallBounce();
		return ContactEntity::kTop;
	}
	else if (position_y >= WINDOW_HEIGHT) {
		y_speed_ *= -1;
		playWallBounce();
		return ContactEntity::kBottom;
	}
	// Check for collision against a paddle. Short circuit if paddle contacted to save processing
	else if (deflectFromPaddle(pSession_->getPaddleOne())) {
		playPaddleHit();
		return ContactEntity::kPaddleOne;
	}
	else if (deflectFromPaddle(pSession_->getPaddleTwo())) {
		playPaddleHit();
		return ContactEntity::kPaddleTwo;
	}

	return ContactEntity::kNone;
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
			x_speed_ *= -1;
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
			x_speed_ *= -1;
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
	// Handle serve based on active powerup (if powerup is serve-centric)
	switch (pSession_->active_powerup) {
		case PowerUps::kFire:
			// Double ball speed
			this->x_speed_ *= 2;
			break;
		case PowerUps::kConfusion:
			wave_init_x = position_x;
			wave_init_y = position_y;
			break;
		default:
			// Normal serve
			break;
	}
	ball_served = true;

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

/*
When ConfusionBall is active, ball control is taken over by this function. 
The ball's movement is controlled based on position now rather than speed.
*/
void Ball::transformWaveMovement() {
	// Calculate angle and speed of ball
	wave_direction = atan2(y_speed_, x_speed_);
	wave_speed = sqrt(pow(x_speed_, 2) + pow(y_speed_, 2));
	
	// Move ball based on wave details
	wave_distance += wave_speed;
	position_x = wave_init_x + cos(wave_direction) * wave_distance;
	position_y = wave_init_y + sin(wave_direction) * wave_distance;

	// Adjust the new locatiob based on wave position
	const float deviation = sin(wave_distance * M_PI / wave_period) * wave_amplitude;

	position_x += sin(wave_direction) * deviation;
	position_y -= cos(wave_direction) * deviation;
}
