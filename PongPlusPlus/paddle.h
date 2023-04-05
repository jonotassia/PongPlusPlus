#ifndef PADDLE_H
#define PADDLE_H

#include "game.h"
#include "definitions.h"

// Forward declaration
class Player;

class Paddle {
public:
	// Constructor/Destructor
	Paddle(Player* pPlayer, float position_x);

	// Getters/Setters
	void setPlayer(Player* pPlayer) { pPlayer_ = pPlayer; };
	Player* getPlayer() { return pPlayer_; };
	
	// Geometry
	float width{ WINDOW_WIDTH / 60 };
	float height{ WINDOW_HEIGHT / 6 };
	float position_x;  // X Location of top-left corner
	float position_y { WINDOW_HEIGHT / 2 - height / 2};  // Y Location of top-left corner

	// Movement
	float speed{ 2 };
	Direction direction{ Direction::kNone };

	// Proprietary functions
	void Update();
	bool checkBoundary(Direction direction);
	void catchBall();

private:
	Player* pPlayer_;
};

#endif