#ifndef RENDER_H
#define RENDER_H

#include <SDL.h>

// Forward declarations and constants
const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;
class Game;

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
	void drawNet();
	void drawScreen();
	void drawScore();
	void drawBall();
	void drawPaddles();
	void drawVictoryScreen();

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