#include <iostream>
#include <SDL.h>
#include <string>

#include "render.h"

Renderer::~Renderer() {
	SDL_DestroyRenderer(pRrenderer_);
	SDL_DestroyWindow(pWindow_);
	SDL_Quit();
}

void Renderer::setColorScheme() {
	switch (pGame_->color_scheme_) {
		case(PowerUps::kNone): SDL_SetRenderDrawColor(pRrenderer_, 0xFF, 0xFF, 0xFF, 0xFF); break;
		case(PowerUps::kFire): SDL_SetRenderDrawColor(pRrenderer_, 0xFA, 0x8D, 0x22, 0xFF); break;
		case(PowerUps::kIce): SDL_SetRenderDrawColor(pRrenderer_, 0x27, 0xB7, 0xDE, 0xFF); break;
		case(PowerUps::kSun): SDL_SetRenderDrawColor(pRrenderer_, 0xF6, 0xFA, 0x17, 0xFF); break;
		case(PowerUps::kShadow): SDL_SetRenderDrawColor(pRrenderer_, 0x67, 0x4E, 0xA7, 0xFF); break;
		case(PowerUps::kSniper): SDL_SetRenderDrawColor(pRrenderer_, 0xF6, 0xFA, 0x17, 0xFF); break;
	}
}

void Renderer::drawNet() {
	SDL_RenderDrawLine(pRrenderer_, WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
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
	SDL_SetRenderDrawColor(pRenderer_, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(pRenderer_);

	// Rendering for each frame below. Color set based on current power up
	setColorScheme();
	drawNet();
	drawScore();

	// Present the backbuffer
	SDL_RenderPresent(pRenderer_);
}
