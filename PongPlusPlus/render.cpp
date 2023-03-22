#include <iostream>
#include <SDL.h>
#include <string>

#include "render.h"

Renderer::~Renderer() {
	SDL_DestroyRenderer(renderer);
	SDL_DestroyWindow(window);
	SDL_Quit();
}

void Renderer::setColorScheme() {
	switch (color_scheme) {
		case(PowerUps::kNone): SDL_SetRenderDrawColor(renderer, 0xFF, 0xFF, 0xFF, 0xFF); break;
		case(PowerUps::kFire): SDL_SetRenderDrawColor(renderer, 0xFA, 0x8D, 0x22, 0xFF); break;
		case(PowerUps::kIce): SDL_SetRenderDrawColor(renderer, 0x27, 0xB7, 0xDE, 0xFF); break;
		case(PowerUps::kSun): SDL_SetRenderDrawColor(renderer, 0xF6, 0xFA, 0x17, 0xFF); break;
		case(PowerUps::kShadow): SDL_SetRenderDrawColor(renderer, 0x67, 0x4E, 0xA7, 0xFF); break;
		case(PowerUps::kSniper): SDL_SetRenderDrawColor(renderer, 0xF6, 0xFA, 0x17, 0xFF); break;
	}
}

void Renderer::drawNet() {
	SDL_RenderDrawLine(renderer, WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
}

void Renderer::drawScore() {
	// TODO: Add score renderer above screen (consider a second window that is born of an abstract screen class)
}

void Renderer::drawBall() {
	// TODO: Add facility to draw current location of ball
}

void Renderer::drawPaddle() {
	// TODO: Add facility to draw current location of paddle
}

void Renderer::drawScreen() {
	// Clear the window to black
	SDL_SetRenderDrawColor(renderer, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(renderer);

	// Rendering for each frame below. Color set based on current power up
	setColorScheme();
	drawNet();
	drawScore();

	// Present the backbuffer
	SDL_RenderPresent(renderer);
}
