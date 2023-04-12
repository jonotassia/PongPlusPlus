#ifndef PLAYER_H
#define PLAYER_H

#include "definitions.h"

// Forward declaration
class Controller;
class Paddle;

class Player {
public:
	// Class Enums
	enum class PlayerNum { kOne, kTwo };
	
	// Constructors/Destructors
	Player(PlayerNum num);
	~Player();

	// Getters/Setters
	Paddle* getPaddle() { return pPaddle_; }
	void setPaddle(Paddle* pPaddle) { pPaddle_ = pPaddle; }
	
	// Session data
	PlayerNum player_num;							// Player's one or two
	std::uniform_int_distribution<> powerup_generator{1, 6};   // Randomly selects a number of powerup
	PowerUps selected_powerup{ static_cast<PowerUps>(powerup_generator(MTE)) };  // PowerUp selected by the player
	bool serve_owner{ (player_num == PlayerNum::kOne) ? true : false };  // Serve owner set to pOne on creation
	int points { 0 };

	// Player stats
	int total_wins { 0 };
	int total_losses { 0 };
	int total_points_won { 0 };
	int total_points_lost { 0 };

	// Proprietary functions
	void savePlayerStats();
	void loadPlayerStats();

private:
	friend class Controller;
	Paddle* pPaddle_;
};

#endif