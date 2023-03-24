#include <SDL.h>

#include "game.h"
#include "render.h"
#include "paddle.h"
#include "ball.h"

Game::Game(Renderer* pRenderer) : pRenderer_(pRenderer) {
	pRenderer->setGame(this);
	paddle_one = new Paddle(getPlayerOne(), 10);
	paddle_two = new Paddle(getPlayerTwo(), WINDOW_WIDTH - 20);
	ball = new Ball(getPaddleOne(), getPaddleTwo());
}

Game::~Game() {
	delete paddle_one;
	delete paddle_two;
	delete ball;
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
	paddle_one->Update();
	paddle_two->Update();
	ball->Update();
}

bool Game::checkGameOver() {
	if (pPlayerOne_->points == 10 || pPlayerTwo_->points == 10) {
		return true;
	}
	return false;
}