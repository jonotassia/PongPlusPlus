#include "game.h"

const int WINDOW_WIDTH = 1280;
const int WINDOW_HEIGHT = 720;

class Renderer {
public:
	~Renderer();
	void setColorScheme();
	void drawNet();
	void drawScreen();
	void drawScore();
	void drawBall();
	void drawPaddle();

private:
	SDL_Window* window = SDL_CreateWindow("PongPlusPlus", 0, 0, WINDOW_WIDTH, WINDOW_HEIGHT, SDL_WINDOW_SHOWN);
	SDL_Renderer* renderer = SDL_CreateRenderer(window, -1, 0);
	PowerUps color_scheme = PowerUps::kNone;
};