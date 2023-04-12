#ifndef PADDLE_H
#define PADDLE_H

#include "definitions.h"

// Forward declaration
class Player;
class Session;

class Paddle {
public:
	// Constructor/Destructor
	Paddle(Session* pSession, Player* pPlayer, float position_x);

	// Static class variables
	static constexpr float init_height{ WINDOW_HEIGHT / 6 };
	static constexpr float init_width{ WINDOW_WIDTH / 60 };
	
	// Getters/Setters
	void setPlayer(Player* pPlayer) { pPlayer_ = pPlayer; };
	Player* getPlayer() { return pPlayer_; };
	
	// Geometry
	float width{ init_width };
	float height{ init_height };
	float position_x;  // X Location of top-left corner
	float position_y { WINDOW_HEIGHT / 2 - height / 2};  // Y Location of top-left corner

	// Movement
	float speed{ 1.5 };
	Direction direction{ Direction::kNone };

	// Gameplay
	bool ball_caught{ false };   // Indicates if this paddle has caught the ball

	// Proprietary functions
	void Update();
	bool checkBoundary(Direction direction);
	void catchBall();
	void resetDirection();
	void shrinkPaddle(float percent);

private:
	Player* pPlayer_;
	Session* pSession_;

	// Gameplay
	int catches_remaining_{ 1 };  // Each attempt at catching in a given session decrements this by 1
};

#endif