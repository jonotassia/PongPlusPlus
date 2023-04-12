#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>
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
	void setColorScheme();
	void drawBackground();
	void drawNet();
	void drawScreen();
	void drawScore(int score, int x, int y);
	void drawBall();
	void drawPaddles();
	void drawVictoryScreen(Player* winner, Player* loser);

private:
	SDL_Window* pWindow_ = SDL_CreateWindow(
		"PongPlusPlus", 
		SDL_WINDOWPOS_CENTERED, 
		SDL_WINDOWPOS_CENTERED, 
		WINDOW_WIDTH, 
		WINDOW_HEIGHT, 
		SDL_WINDOW_SHOWN);
	SDL_Renderer* pRenderer_ = SDL_CreateRenderer(pWindow_, -1, 0);
	Game* pGame_ { nullptr };
};

#endif