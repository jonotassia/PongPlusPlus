#ifndef BALL_H
#define BALL_H

#include "definitions.h"

// Forward declarations
class Paddle;
class Session;

class Ball {
public:
	// Constructor/Destructor;
	Ball(Session* pSession);
	
	// Geometry
	float width{ 5 };
	float height{ 5 };
	float position_x { WINDOW_WIDTH / 2 - width / 2 };  // X Location of top-left corner
	float position_y { WINDOW_HEIGHT / 2 - height / 2};  // Y Location of top-left corner

	// Serve ball tracker
	bool ball_served = false;

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
	float x_speed_{ 0.5 };
	float y_speed_{ y_speed_generator_(MTE) / (float)10 };
	void speedBallUp(float increment);

	// Linkages
	Session* pSession_;
};

#endif