#pragma once

#include <memory>

#include "ball.h"
#include "paddle.h"
#include "render.h"

enum class PowerUps {
	kNone,
	kFire,
	kIce,
	kSun,
	kShadow,
	kSniper
};

enum class Direction {
	kUp,
	kDown,
	kLeft,
	kRight
};

class Game {
public:
	// Constructor/destructor
	Game(Renderer *renderer);

	// Getters/Setters
	Player* getPlayerOne() const { return pPlayerOne_.get(); };
	Player* getPlayerTwo() const { return pPlayerTwo_.get(); };
	Ball* getBall() const { return pBall_; };
	Paddle* getPaddleOne() const { return pPaddleOne_; };
	Paddle* getPaddleTwo() const { return pPaddleTwo_; };
	
	// Proprietary functions
	void Run();
	void Update();
	bool checkGameOver();

	// Public variables
	PowerUps color_scheme_ = PowerUps::kNone;

private:
	// Renderer
	Renderer* pRenderer_;

	// Persistent objects (unique ownership)
	std::unique_ptr<Player> pPlayerOne_ = std::make_unique<Player>(PlayerNum::kOne);
	std::unique_ptr<Player> pPlayerTwo_ = std::make_unique<Player>(PlayerNum::kTwo);

	// Game objects
	Paddle* pPaddleOne_ = Paddle(pPlayerOne_.get(), 20);
	Paddle* pPaddleTwo_ = Paddle(pPlayerTwo_.get(), WINDOW_WIDTH - 20);
	Ball *pBall_;
};

// TODO: Create new session object to own paddles for each game