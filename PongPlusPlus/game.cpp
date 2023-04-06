#include <SDL.h>

#include "game.h"
#include "control.h"
#include "render.h"
#include "paddle.h"
#include "ball.h"


Game::Game(Renderer* pRenderer) : pRenderer_(pRenderer) {
	pRenderer_->setGame(this);
}

/*
Establishes the game loop, which includes:
	* Input handling
	* Game updates
	* Rendering
*/
void Game::Run() {
	bool running = true;
	
	// Declare variables for frame cap
	Uint32 start, end;
	float elapsed;

	// Continue looping and processing events until user exits. Handle input will change value of running as needed.
	while (running) {
		start = SDL_GetTicks();
		
		// Update game objects with input and draw screen components
		SDL_Event event;
		while (SDL_PollEvent(&event)) {
			pController_->handleInput(running, event);
		}
		this->Update(running);
		pRenderer_->drawScreen();

		// Calculate delay between loops to cap at 60 FPS
		end = SDL_GetTicks();
		float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
		SDL_Delay(FPS_ADJUST - elapsed);
	}
}

void Game::Update(bool& running) {
	// Check if game over. If game over, reset points of both players and draw victory screen
	if (checkGameOver()) {
		pRenderer_->drawVictoryScreen();
		pPlayerOne_->points = 0;
		pPlayerTwo_->points = 0;
	}
	
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