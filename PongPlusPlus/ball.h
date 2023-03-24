#ifndef BALL_H
#define BALL_H

#include "game.h"
#include "render.h"

// Forward declarations
class Paddle;

class Ball {
public:
	// Constructor/Destructor;
	Ball(Paddle* paddle_one, Paddle* paddle_two);
	
	// Geometry
	float position_x { WINDOW_WIDTH / 2 - width / 2 };  // X Location of central point
	float position_y { WINDOW_HEIGHT / 2 - height / 2};  // Y Location of central point
	float width { 5 };
	float height { 5 };

	// Proprietary functions
	void moveBall();
	bool checkContact(Paddle* paddle);
	bool checkWinningPosition(Paddle* paddle);
	bool deflectFromPaddle(Paddle* paddle);
	void playWallBounce();
	void playPaddleHit();

private:
	// Movement
	float x_speed_ { 1 };
	float y_speed_ { 1 };

	// Linkages
	Paddle* pPaddleOne_;
	Paddle* pPaddleTwo_;
};

#endif