#include <SDL.h>

#include "game.h"
#include "render.h"
#include "paddle.h"
#include "ball.h"

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
		// Check if game over. If game over, reset points of both players and draw victory screen
		if (checkGameOver()) {
			pRenderer_->drawVictoryScreen();
			pPlayerOne_->points = 0;
			pPlayerTwo_->points = 0;
		}
		// Update game objects and draw screen components
		this->Update();
		pRenderer_->drawScreen();
	}
}

void Game::Update() {
	// Move each object, ensuring the ball moves last to ensure that it can check for collisions
	pSession_->Update();
}

void Game::resetSession() {
	pSession_.reset(new Session(this));
}

bool Game::checkGameOver() {
	if (pPlayerOne_->points == 10) {
		pPlayerOne_->total_wins++;
		return true;
	}
	else if (pPlayerTwo_->points == 10) {
		pPlayerTwo_->total_wins++;
		return true;
	}
	return false;
}

Session::Session(Game* pGame) : pGame_(pGame) {
	pPaddleOne_ = new Paddle(pGame_->getPlayerOne(), 10);
	pPaddleTwo_ = new Paddle(pGame_->getPlayerTwo(), WINDOW_WIDTH - 20);
	pBall_ = new Ball(getPaddleOne(), getPaddleTwo());
}

Session::~Session() {
	delete pPaddleOne_;
	delete pPaddleTwo_;
	delete pBall_;
}

void Session::Update() {
	// Move each object, ensuring the ball moves last to ensure that it can check for collisions
	pPaddleOne_->Update();
	pPaddleTwo_->Update();
	pBall_->Update();
	
	if (pBall_->checkWinningPosition(pPaddleOne_)) {
		pPaddleTwo_->getPlayer()->points++;
		pGame_->resetSession();
	}
	else if (pBall_->checkWinningPosition(pPaddleTwo_)) {
		pPaddleOne_->getPlayer()->points++;
		pGame_->resetSession();
	}
}