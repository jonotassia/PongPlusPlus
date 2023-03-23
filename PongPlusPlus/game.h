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
	Game(Renderer *pRenderer);

	// Getters/Setters
	Player* getPlayerOne() { return pPlayerOne_.get(); };
	Player* getPlayerTwo() { return pPlayerTwo_.get(); };
	Ball& getBall() { return ball; };
	Paddle& getPaddleOne() { return paddle_one; };
	Paddle& getPaddleTwo() { return paddle_two; };
	
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
	Paddle paddle_one = Paddle(getPlayerOne(), 20);
	Paddle paddle_two = Paddle(getPlayerTwo(), WINDOW_WIDTH - 20);
	Ball ball;
};

// TODO: Create new session object to own paddles and balls for each game