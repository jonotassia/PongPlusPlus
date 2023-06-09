#include "SDL2/SDL.h"

#include "game.h"
#include "control.h"
#include "render.h"
#include "paddle.h"
#include "ball.h"
#include "player.h"


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
			// Break if this is a phantom press of the button (which is automatic with letter keys)
			if (event.key.keysym.sym != 0 && event.key.keysym.scancode != SDL_SCANCODE_UNKNOWN) {
				pController_->handleInput(running, event);
			}
		}
		this->Update(running);
		pRenderer_->drawScreen();

		// Calculate delay between loops to cap at 60 FPS
		end = SDL_GetTicks();
		float elapsed = (end - start) / (float)SDL_GetPerformanceFrequency() * 1000.0f;
		SDL_Delay(FPS_ADJUST - elapsed);
	}
}

/*
Triggers updates to the session. Checks that the game is over. If it is, reset points.
*/
void Game::Update(bool& running) {
	// Check if game over. If game over, reset points of both players and draw victory screen
	if (checkGameOver()) {
		pPlayerOne_->points = 0;
		pPlayerTwo_->points = 0;
	}
	
	// Move each object, ensuring the ball moves last to ensure that it can check for collisions
	pSession_->Update();
}

/*
Resets the session object, deleting all game objects and then generating new ones.
*/
void Game::resetSession() {
	pSession_.reset(new Session(this));
}

/*
Checks if either side has won. If so, increments player wins and triggers victory screen.
*/
bool Game::checkGameOver() {
	if (pPlayerOne_->points == 10) {
		pPlayerOne_->total_wins++;
		pRenderer_->drawVictoryScreen(pPlayerOne_.get(), pPlayerTwo_.get());
		return true;
	}
	else if (pPlayerTwo_->points == 10) {
		pPlayerTwo_->total_wins++;
		pRenderer_->drawVictoryScreen(pPlayerTwo_.get(), pPlayerOne_.get());
		return true;
	}
	return false;
}

Session::Session(Game* pGame) : pGame_(pGame) {
	pPaddleOne_ = new Paddle(this, pGame_->getPlayerOne(), 10);
	pPaddleTwo_ = new Paddle(this, pGame_->getPlayerTwo(), WINDOW_WIDTH - 30);
	pBall_ = new Ball(this);
}

Session::~Session() {
	delete pPaddleOne_;
	delete pPaddleTwo_;
	delete pBall_;
}


// Copy constructor
Session::Session(Session& src) {
	// Handle non-owning references. 
	// There should only be one game at a time, so the session should always be linked to the same game, not a duplicate of it.
	this->pGame_ = src.pGame_;

	// Handle owning references
	*this->pPaddleOne_ = *src.pPaddleOne_;
	*this->pPaddleTwo_ = *src.pPaddleTwo_;
	*this->pBall_ = *src.pBall_;
}	

// Copy assignment constructor
Session& Session::operator=(Session& src) {
	if (&src == this) {
		return *this;
	}

	// Handle non-owning references. 
	// There should only be one game at a time, so the session should always be linked to the same game, not a duplicate of it.
	this->pGame_ = src.pGame_;

	// Handle owning references
	*this->pPaddleOne_ = *src.pPaddleOne_;
	*this->pPaddleTwo_ = *src.pPaddleTwo_;
	*this->pBall_ = *src.pBall_;

	return *this;
}	

// Move constructor
Session::Session(Session&& src) {
	// Handle non-owning references. 
	// There should only be one game at a time, so the session should always be linked to the same game, not a duplicate of it.
	this->pGame_ = src.pGame_;

	// Handle owning references
	*this->pPaddleOne_ = *src.pPaddleOne_;
	delete src.pPaddleOne_;

	*this->pPaddleTwo_ = *src.pPaddleTwo_;
	delete src.pPaddleTwo_;

	*this->pBall_ = *src.pBall_;
	delete src.pBall_;
}

// Move assignment constructor
Session& Session::operator=(Session&& src) {
	if (&src == this) {
		return *this;
	}

	// Handle owning references
	*this->pPaddleOne_ = *src.pPaddleOne_;
	delete src.pPaddleOne_;

	*this->pPaddleTwo_ = *src.pPaddleTwo_;
	delete src.pPaddleTwo_;

	*this->pBall_ = *src.pBall_;
	delete src.pBall_;

	return *this;
}    	

/*
Updates the session, which covers the following:
	* Deactivate powerup if powerup duration has hit 0.
	* Update paddles
	* Update ball
	* Reset session if a point has been scored.
*/
void Session::Update() {
	// Reset powerup if duration has passed
	if (!this->powerup_duration) {
		this->active_powerup = PowerUps::kNone;
	}
	
	// Move each object, ensuring the ball moves last to ensure that it can check for collisions
	pPaddleOne_->Update();
	pPaddleTwo_->Update();
	pBall_->Update();
	
	// Check if a player has scored
	if (pBall_->checkWinningPosition(pPaddleOne_)) {
		pPaddleTwo_->getPlayer()->points++;
		pPaddleOne_->getPlayer()->serve_owner = true;
		pGame_->resetSession();
	}
	else if (pBall_->checkWinningPosition(pPaddleTwo_)) {
		pPaddleOne_->getPlayer()->points++;
		pPaddleTwo_->getPlayer()->serve_owner = true;
		pGame_->resetSession();
	}
}

/* 
Use this method for consistent powerup handling regardless of activation source.
	* Activates powerup
	* Sets duration by powerup type
*/
void Session::activatePowerup(PowerUps powerup, Paddle* paddle) {
	// Activate powerups
	active_powerup = powerup;
	paddle->powerup_available = false;
	powerup_owner = paddle;

	// Set powerup duration
	switch (active_powerup) {
		case(PowerUps::kNone): powerup_duration = 0; break;
		case(PowerUps::kFire): powerup_duration = 10; break;
		case(PowerUps::kIce): powerup_duration = 10; break;
		case(PowerUps::kSun): powerup_duration = 5; break;
		case(PowerUps::kShadow): powerup_duration = 3; break;
		case(PowerUps::kConfusion): powerup_duration = 5; break;
	}
}