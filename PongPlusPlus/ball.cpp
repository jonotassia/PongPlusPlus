#include "ball.h"

/*
Moves the ball, taking into consideration ball speed, potential direction changes from contact, and winning points
*/
void Ball::moveBall() {
	position_x += x_speed;
	position_y += y_speed;
	
	for (auto paddle : paddles_) {
		if (checkContact(paddle)) {
			break;
		}
		elif(checkWinningPosition(paddle)) {
			paddle->pPlayer_->points++;
			break;
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
		y_speed -= 2 * y_speed;
		return true;
	}
	// Check for collision against a paddle. Short circuit if paddle contacted to save processing
	elif deflectFromPaddle(paddle) {
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
	paddle_x_lim = paddle->pPlayer_->player_num == PlayerNum::kOne : paddle->position_x + (paddle->width / 2) ? paddle->position_x - (paddle->width / 2);
	paddle_y_max = paddle->position_y + (paddle->height / 2);
	paddle_y_min = paddle->position_y - (paddle->height / 2);
	
	// TODO: Optimize these checks so that we don't have to test separately for kOne and kTwo
	if paddle->pPlayer_->player_num == PlayerNum::kOne {
		// Check boundaries against paddle one, then inverse x-speed
		if (position_y >= paddle_y_min && position_y <= paddle_y_max && position_x <= paddle_x_lim) {
			x_speed -= 2 * x_speed;
			return true;
		}
	}
	else {
		// Check boundaries against paddle two, then inverse x-speed
		if (position_y >= paddle_y_min && position_y <= paddle_y_max && position_x >= paddle_x_lim) {
			x_speed -= 2 * x_speed;
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
	// Calculate paddle x boundaries
	paddle_x_lim = paddle->pPlayer_->player_num == PlayerNum::kOne : paddle->position_x - (paddle->width / 2) ? paddle->position_x + (paddle->width / 2);

	// TODO: Optimize these checks so that we don't have to test separately for kOne and kTwo
	if paddle->pPlayer_->player_num == PlayerNum::kOne{
		// Check boundaries against paddle one, then inverse x-speed
		if (position_x < paddle_x_lim) {
			return true;
		}
	}
	else {
		// Check boundaries against paddle two, then inverse x-speed
		if (position_x > paddle_x_lim) {
			return true;
		}
	}
	return false;
}