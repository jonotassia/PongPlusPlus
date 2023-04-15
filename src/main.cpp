#include <iostream>
#include "SDL2/SDL.h"
#include <string>

#include "game.h"
#include "render.h"

int main(int argc, char *args[])
{
	// Initialize SDL components
	SDL_Init(SDL_INIT_VIDEO);
	
	// Initialize game components
	Renderer renderer;
	Game game(&renderer);

	// Begin game loop
	game.Run();


	return 0;
}