#ifndef PADDLE_H
#define PADDLE_H

#include "render.h"
#include "game.h"

class Player;

class Paddle {
public:
	// Constructor/Destructor
	Paddle(Player* pPlayer, float position_x);

	// Getters/Setters
	void setPlayer(Player* pPlayer) { pPlayer_ = pPlayer; };
	Player* getPlayer() { return pPlayer_; };
	
	// Geometry
	float position_x;  // X Location of central point
	float position_y { WINDOW_HEIGHT / 2 - height / 2};  // Y Location of central point
	float width { WINDOW_WIDTH / 60 };
	float height { WINDOW_HEIGHT / 6 };

	// Proprietary functions
	void movePaddle();

private:
	// Movement
	float speed { 2 };
	Game::Direction direction_{Game::Direction::kNone};
	Player* pPlayer_;
};

class PowerPaddle : private Paddle {
public:
	void catchBall();
};

#endif