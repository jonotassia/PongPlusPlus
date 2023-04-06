#ifndef BALL_H
#define BALL_H

#include "game.h"
#include "definitions.h"

// Forward declarations
class Paddle;

class Ball {
public:
	// Constructor/Destructor;
	Ball(Paddle* paddle_one, Paddle* paddle_two);
	
	// Geometry
	float width{ 5 };
	float height{ 5 };
	float position_x { WINDOW_WIDTH / 2 - width / 2 };  // X Location of top-left corner
	float position_y { WINDOW_HEIGHT / 2 - height / 2};  // Y Location of top-left corner

	// Proprietary functions
	void Update();
	bool checkContact(Paddle* paddle);
	bool checkWinningPosition(Paddle* paddle);
	bool deflectFromPaddle(Paddle* paddle);
	void serveBall();
	void playWallBounce();
	void playPaddleHit();

private:	
	// Movement
	std::uniform_int_distribution<> y_speed_generator_{ 7, 10 };
	float x_speed_{ 1 };
	float y_speed_{ y_speed_generator_(MTE) / (float)10 };

	// Serve ball tracker
	bool ball_served = false;

	// Linkages
	Paddle* pPaddleOne_;
	Paddle* pPaddleTwo_;
};

#endif