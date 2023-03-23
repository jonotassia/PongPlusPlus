#include <SDL.h>

#include "game.h"

Game::Game(Renderer* pRenderer) : pRenderer_(pRenderer) {
	pRenderer->setGame(this);
}

void Game::Run() {
	bool running = true;

	// Continue looping and processing events until user exits
	while (running)
	{
		SDL_Event event;
		while (SDL_PollEvent(&event))
		{
			if (event.type == SDL_QUIT)
			{
				running = false;
			}
			else if (event.type == SDL_KEYDOWN)
			{
				if (event.key.keysym.sym == SDLK_ESCAPE)
				{
					running = false;
				}
			}
		}
		// Update game objects and draw screen components
		if (checkGameOver()) {
			pRenderer_->drawVictoryScreen();
			running = false;
		}
		this->Update();
		pRenderer_->drawScreen();
	}
}

void Game::Update() {
	// Move each object, ensuring the ball moves last to ensure that it can check for collisions
	pPaddleOne_->movePaddle();
	pPaddleTwo_->movePaddle();
	pBall_->moveBall();
}

bool Game::checkGameOver() {
	if (pPlayerOne_->points == 10 || pPlayerTwo_->points == 10) {
		return true;
	}
	return false;
}