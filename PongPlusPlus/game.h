#include "ball.h"
#include "paddle.h"
#include "render.h"

enum class PowerUps {
	kNone,
	kFire,
	kIce,
	kSun,
	kShadow,
	kSniper
};

enum class Direction {
	kUp,
	kDown,
	kLeft,
	kRight
};

class Game {
public:
	// Constructor/destructor
	Game(Renderer *renderer);
	
	// Proprietary functions
	void Run();
	void Update();

	// Public variables
	PowerUps color_scheme_ = PowerUps::kNone;

private:
	// Renderer
	Renderer* pRenderer_;

	// Game objects
	Paddle *pPaddleOne_;
	Paddle *pPaddleTwo_;
	Ball *pBall_;
};