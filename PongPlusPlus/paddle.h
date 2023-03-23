#include "player.h"
#include "game.h"

class Paddle {
public:
	// Constructor/Destructor
	Paddle(Player* pPlayer);

	// Getters/Setters
	void setPlayer(Player* pPlayer) { pPlayer_ = pPlayer };
	Player* getPlayer() { return pPlayer_ };
	
	// Geometry
	float position_x;  // X Location of central point
	float position_y;  // Y Location of central point
	float width;
	float height;

	// Proprietary functions
	void Update();
	void movePaddle();

private:
	// Movement
	float speed;
	Direction direction_;
	Player* pPlayer_;
};

class PowerPaddle : private Paddle {
public:
	void catchBall();
};