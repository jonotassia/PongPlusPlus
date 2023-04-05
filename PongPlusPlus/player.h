#ifndef PLAYER_H
#define PLAYER_H

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
	PlayerNum player_num;
	int cooldown_timer { 20 };
	bool powerup_available { false };
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