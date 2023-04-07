#include <SDL.h>

#include "control.h"
#include "game.h"
#include "paddle.h"
#include "ball.h"

/*
Awaits input from user. Based on input, routes to correct function.
Once input has been received, reset the direction of the paddle.
*/
void Controller::handleInput(bool& running, SDL_Event& e) const {	
	// Reset the paddles to kNone direction
	resetPaddles();

	if (e.type == SDL_QUIT) {
		running = false;
	}
	else if (e.type == SDL_KEYDOWN) {
		// Create a pointer to the SDL key state
		const Uint8* key_state = SDL_GetKeyboardState( NULL );
		
		// Check player one input
		if (key_state[SDL_SCANCODE_W]) {
			this->changeDirection(Direction::kUp, *pPlayerOne_);
		}
		else if (key_state[SDL_SCANCODE_S]) {
			this->changeDirection(Direction::kDown, *pPlayerOne_);
		}
		else if (key_state[SDL_SCANCODE_SPACE]) {
			if (pPlayerOne_->serve_owner && !this->pGame_->getSession()->getBall()->ball_served) {
				this->pGame_->getSession()->getBall()->serveBall();
			}
		}
		else if (key_state[SDL_SCANCODE_D]) {
			this->catchBall(*pPlayerOne_);
		}

		// Check player two input
		if (key_state[SDL_SCANCODE_UP]) {
			this->changeDirection(Direction::kUp, *pPlayerTwo_);
		}
		else if (key_state[SDL_SCANCODE_DOWN]) {
			this->changeDirection(Direction::kDown, *pPlayerTwo_);
		}
		else if (key_state[SDL_SCANCODE_RETURN]) {
			if (pPlayerTwo_->serve_owner && !this->pGame_->getSession()->getBall()->ball_served) {
				this->pGame_->getSession()->getBall()->serveBall();
			}
		}
		else if (key_state[SDL_SCANCODE_KP_ENTER]) {
			if (pPlayerTwo_->serve_owner && !this->pGame_->getSession()->getBall()->ball_served) {
				this->pGame_->getSession()->getBall()->serveBall();
			}
		}
		else if (key_state[SDL_SCANCODE_RCTRL]) {
			this->catchBall(*pPlayerTwo_);
		}
	}
}

// Changes direction of the paddle based on user input
void Controller::changeDirection(Direction direction, Player& player) const {
	player.pPaddle_->direction = direction;
}

// Triggers the paddle to catch the ball, if criteria are met
void Controller::catchBall(Player& player) const {
	player.pPaddle_->catchBall();
}

// Reset paddle directions
void Controller::resetPaddles() const {
	pPlayerOne_->pPaddle_->resetDirection();
	pPlayerTwo_->pPaddle_->resetDirection();
}