#ifndef GAME_H
#define GAME_H

#include <memory>
#include "control.h"
#include "definitions.h"
#include "player.h"

// Forward Declarations
class Renderer;
class Paddle;
class Ball;
class Session;

class Game {
public:
	// Constructor/destructor
	Game(Renderer *pRenderer);

	// Getters/Setters
	Player* getPlayerOne() { return pPlayerOne_.get(); };
	Player* getPlayerTwo() { return pPlayerTwo_.get(); };
	Session* getSession() { return pSession_.get(); };
	
	// Proprietary functions
	void Run();
	void Update(bool& running);
	bool checkGameOver();
	void resetSession();

	// Public variables
	PowerUps color_scheme_ = PowerUps::kNone;

private:
	// Renderer
	Renderer* pRenderer_;

	// Persistent objects (unique ownership)
	std::unique_ptr<Player> pPlayerOne_ = std::make_unique<Player>(Player::PlayerNum::kOne);
	std::unique_ptr<Player> pPlayerTwo_ = std::make_unique<Player>(Player::PlayerNum::kTwo);
	std::unique_ptr<Controller> pController_ = std::make_unique<Controller>(pPlayerOne_.get(), pPlayerTwo_.get());

	// Session objects (unique ownership)
	std::unique_ptr<Session> pSession_ = std::make_unique<Session>(this);
};

/*
Session objects control invidual scenarios, such as access to the main menu or each rally of a match
*/
class Session {
public:
	// Constructors/Destructors
	Session(Game* pGame);
	~Session();

	// Getters/Setters from session class
	Ball* getBall() { return pBall_; };
	Paddle* getPaddleOne() { return pPaddleOne_; };
	Paddle* getPaddleTwo() { return pPaddleTwo_; };

	// Proprietary Functions
	void Update();
	
private:
	// Game objects
	friend class Game;
	Paddle* pPaddleOne_;
	Paddle* pPaddleTwo_;
	Ball* pBall_;

	// Linkages
	Game* pGame_;
};

#endif