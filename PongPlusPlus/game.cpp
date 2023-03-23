#include "game.h"

Game::Game(Renderer *pRenderer) : renderer(pRenderer) {
	pRenderer->setGame(this);
}

void Game::Run() {
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
		// Update game objects and draw screen components
		this->Update();
		pRenderer->drawScreen();
	}
}

void Game::Update() {
	// TODO: Ensure each game object is updated to reflect new values
}