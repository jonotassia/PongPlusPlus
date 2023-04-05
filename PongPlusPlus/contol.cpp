#include <SDL.h>

#include "control.h"
#include "game.h"
#include "paddle.h"

/*
Awaits input from user. Based on input, routes to correct function.
Once input has been received, reset the direction of the paddle.
*/
void Controller::handleInput(bool& running) const {
	SDL_Event e;
	while (SDL_PollEvent(&e)) {
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
			}
			// Check player two input
			switch (e.key.keysym.sym) {
				case SDLK_UP:
					this->changeDirection(Direction::kUp, *pPlayerTwo_);
					break;
				case SDLK_DOWN:
					this->changeDirection(Direction::kDown, *pPlayerTwo_);
					break;
			}
		}
		// Reset paddle directions
		pPlayerOne_->pPaddle_->direction = Direction::kNone;
		pPlayerTwo_->pPaddle_->direction = Direction::kNone;
	}
}

// Changes direction of the paddle based on user input
void Controller::changeDirection(Direction direction, Player& player) const {
	player.pPaddle_->direction = direction;
}