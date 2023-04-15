#ifndef RENDER_H
#define RENDER_H

#include "SDL2/SDL.h"
#include "definitions.h"

// Forward declarations and constants
class Game;
class Player;

class Renderer {
public:
	// Constructors/Destructors
	Renderer();
	~Renderer();

	// Getters/Setters
	void setGame(Game* pGame) { pGame_ = pGame; };
	Game* getGame() const { return pGame_; };

	// Proprietary Functions
	void setColorScheme(PowerUps powerup);
	void drawBackground();
	void drawNet();
	void drawScreen();
	void drawScore(int score, int x, int y);
	void drawBall();
	void drawPaddles();
	void drawPowerups();
	void drawVictoryScreen(Player* winner, Player* loser);

private:
	// SDL
	SDL_Window* pWindow_ = SDL_CreateWindow(
		"PongPlusPlus", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		WINDOW_WIDTH, 
		WINDOW_HEIGHT, 
		SDL_WINDOW_SHOWN);
	SDL_Renderer* pRenderer_ = SDL_CreateRenderer(pWindow_, -1, 0);
	
	// Linkages
	Game* pGame_ { nullptr };

	// Color definitions
	SDL_Color white{ 0xFF, 0xFF, 0xFF, 0xFF };
	SDL_Color fire{ 0xFA, 0x8D, 0x22, 0xFF };
	SDL_Color ice{ 0x27, 0xB7, 0xDE, 0xFF };
	SDL_Color sun{ 0xF6, 0xFA, 0x17, 0xFF };
	SDL_Color shadow{ 0x67, 0x4E, 0xA7, 0xFF };
	SDL_Color confusion{ 0xFF, 0x00, 0xFF, 0xFF };
};

#endif