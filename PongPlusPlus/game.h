#include <memory>

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

	// Persistent objects (unique ownership)
	std::unique_ptr<Player> pPlayerOne_ = std::make_unique<Player>(kOne);
	std::unique_ptr<Player> pPlayerTwo_ = std::make_unique<Player>(kTwo);

	// Game objects
	Paddle* pPaddleOne_(pPlayerOne_.get(), 20);
	Paddle* pPaddleTwo_(pPlayerTwo_.get(), WINDOW_WIDTH - 20);
	Ball *pBall_;


};