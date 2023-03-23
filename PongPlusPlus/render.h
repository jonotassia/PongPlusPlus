#include "game.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

class Renderer {
public:
	// Constructors/Destructors
	~Renderer();

	// Getters/Setters
	void setGame(Game* pGame) { pGame_ = pGame};
	Game* getGame() { return pGame_ };

	// Proprietary Functions
	void setColorScheme();
	void drawNet();
	void drawScreen();
	void drawScore();
	void drawBall();
	void drawPaddle();

private:
	SDL_Window* pWindow__ = SDL_CreateWindow("PongPlusPlus", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* pRenderer_ = SDL_CreateRenderer(pWindow_, -1, 0);
	Game* pGame_;
};