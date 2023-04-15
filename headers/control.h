#ifndef CONTROL_H
#define CONTROL_H

#include <memory>
#include "SDL2/SDL.h"

#include "definitions.h"

// Forward declarations
class Player;
class Game;

class Controller {
public:
	// Constructor/Destructor
	Controller(Player* pPlayerOne, Player* pPlayerTwo, Game* pGame) : pPlayerOne_(pPlayerOne), pPlayerTwo_(pPlayerTwo), pGame_(pGame) {}
	
	// Proprietary functions
	void handleInput(bool& running, SDL_Event& e) const;
	void resetPaddles() const;
	void catchBall(Player& player) const;

private:
	// Private functions
	void changeDirection(Direction direction, Player& player) const;
	
	// Non-owning pointers
	Player* pPlayerOne_;
	Player* pPlayerTwo_;
	Game* pGame_;
};

#endif