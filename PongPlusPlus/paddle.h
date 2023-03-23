#include "player.h"
#include "game.h"

class Paddle {
public:
	// Constructor/Destructor
	Paddle(Player* pPlayer, float position_x);

	// Getters/Setters
	void setPlayer(Player* pPlayer) { pPlayer_ = pPlayer };
	Player* getPlayer() { return pPlayer_ };
	
	// Geometry
	float position_x;  // X Location of central point
	float position_y {WINDOW_HEIGHT/2};  // Y Location of central point
	float width;
	float height;

	// Proprietary functions
	void movePaddle();

private:
	// Movement
	float speed { 2 };
	Direction direction_;
	Player* pPlayer_;
};

class PowerPaddle : private Paddle {
public:
	void catchBall();
};