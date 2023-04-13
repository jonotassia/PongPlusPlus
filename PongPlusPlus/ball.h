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

	// Class enum
	enum class ContactEntity{kNone, kTop, kBottom, kPaddleOne, kPaddleTwo};
	
	// Geometry
	float width{ 5 };
	float height{ 5 };
	float position_x { WINDOW_WIDTH / 2 - width / 2 };  // X Location of top-left corner
	float position_y { WINDOW_HEIGHT / 2 - height / 2};  // Y Location of top-left corner

	// Movement
	float x_speed_{ 0 };

	// Serve ball tracker
	bool ball_served = false;

	// Proprietary functions
	void Update();
	ContactEntity checkContact();
	bool checkWinningPosition(Paddle* paddle);
	bool deflectFromPaddle(Paddle* paddle);
	void serveBall();
	void playWallBounce();
	void playPaddleHit();
	void transformWaveMovement();
	void speedBallUp(float increment);

private:	
	// Movement
	std::uniform_int_distribution<> y_speed_generator_{ 3, 6 };	
	float y_speed_{ y_speed_generator_(MTE) / (float)10 };

	// Confusion ball
	float wave_amplitude{ 30 };
	float wave_period{ 30 };
	float wave_distance{ 0 };
	float wave_direction{ 0 };
	double wave_speed{ 0 };
	float wave_init_x{ 0 };
	float wave_init_y{ 0 };

	// Linkages
	Session* pSession_;
};

#endif