#include <vector>

#include "game.h"

class Ball {
public:
	// Geometry
	float position_x;  // X Location of central point
	float position_y;  // Y Location of central point
	float width;
	float height;

	// Proprietary functions
	void moveBall();
	bool checkContact(Paddle* paddle);
	bool checkWinningPosition(Paddle* paddle);
	bool deflectFromPaddle(Paddle* paddle);
	void playWallBounce();
	void playPaddleHit();

private:
	// Movement
	float x_speed_ { 2 };
	float y_speed_ { 2 };

	// Linkages
	Game* pGame_;
	vector<Paddle*> paddles_ { pGame_->pPaddleOne_, pGame_->pPaddleTwo_ };
};