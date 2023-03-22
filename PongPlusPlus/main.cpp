#include <iostream>
#include <SDL.h>
#include <string>

#include "render.h"

int main(int argc, char *args[])
{
	// Initialize SDL components
	SDL_Init(SDL_INIT_VIDEO);
	Renderer renderer;

	// Game logic
	{
		bool running = true;

		// Continue looping and processing events until user exits
		while (running)
		{
			SDL_Event event;
			while (SDL_PollEvent(&event))
			{
				if (event.type == SDL_QUIT)
				{
					running = false;
				}
				else if (event.type == SDL_KEYDOWN)
				{
					if (event.key.keysym.sym == SDLK_ESCAPE)
					{
						running = false;
					}
				}
			}
			renderer.drawScreen();
		}
	}
	return 0;
}