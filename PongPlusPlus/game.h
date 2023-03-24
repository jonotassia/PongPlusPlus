#ifndef GAME_H
#define GAME_H

#include <memory>
#include "player.h"

// Forward Declarations
class Renderer;
class Paddle;
class Ball;

class Game {
public:
	// Constructor/destructor
	Game(Renderer *pRenderer);
	~Game();

	// Getters/Setters
	Player* getPlayerOne() { return pPlayerOne_.get(); };
	Player* getPlayerTwo() { return pPlayerTwo_.get(); };
	Ball* getBall() { return ball; };
	Paddle* getPaddleOne() { return paddle_one; };
	Paddle* getPaddleTwo() { return paddle_two; };
	
	// Proprietary functions
	void Run();
	void Update();
	bool checkGameOver();

	// Class enums
	static enum class PowerUps {
		kNone,
		kFire,
		kIce,
		kSun,
		kShadow,
		kSniper
	};

	static enum class Direction {
		kNone,
		kUp,
		kDown,
		kLeft,
		kRight
	};

	// Public variables
	PowerUps color_scheme_ = PowerUps::kNone;

private:
	// Renderer
	Renderer* pRenderer_;

	// Persistent objects (unique ownership)
	std::unique_ptr<Player> pPlayerOne_ = std::make_unique<Player>(PlayerNum::kOne);
	std::unique_ptr<Player> pPlayerTwo_ = std::make_unique<Player>(PlayerNum::kTwo);

	// Game objects
	Paddle* paddle_one;
	Paddle* paddle_two;
	Ball* ball;
};

// TODO: Create new session object to own paddles and balls for each game

#endif