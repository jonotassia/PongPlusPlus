#ifndef CONTROL_H
#define CONTROL_H

#include <memory>

#include "game.h"
#include "definitions.h"

// Forward declarations
class Player;

class Controller {
public:
	Controller(Player* pPlayerOne, Player* pPlayerTwo) : pPlayerOne_(pPlayerOne), pPlayerTwo_(pPlayerTwo) {}
	void handleInput(bool& running) const;

private:
	void changeDirection(Direction direction, Player& player) const;
	Player* pPlayerOne_;
	Player* pPlayerTwo_;
};

#endif