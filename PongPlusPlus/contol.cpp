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
		// Check player one input
		switch (e.key.keysym.sym) {
			case SDLK_w:
				this->changeDirection(Direction::kUp, *pPlayerOne_);
				break;
			case SDLK_s:
				this->changeDirection(Direction::kDown, *pPlayerOne_);
				break;
			case SDLK_SPACE:
				this->pGame_->getSession()->getBall()->serveBall();
				break;
		}
		// Check player two input
		switch (e.key.keysym.sym) {
			case SDLK_UP:
				this->changeDirection(Direction::kUp, *pPlayerTwo_);
				break;
			case SDLK_DOWN:
				this->changeDirection(Direction::kDown, *pPlayerTwo_);
				break;
			case SDLK_RETURN:
				this->pGame_->getSession()->getBall()->serveBall();
				break;
			case SDLK_KP_ENTER:
				this->pGame_->getSession()->getBall()->serveBall();
				break;
		}
	}
}

// Changes direction of the paddle based on user input
void Controller::changeDirection(Direction direction, Player& player) const {
	player.pPaddle_->direction = direction;
}

// Reset paddle directions
void Controller::resetPaddles() const {
	pPlayerOne_->pPaddle_->resetDirection();
	pPlayerTwo_->pPaddle_->resetDirection();
}