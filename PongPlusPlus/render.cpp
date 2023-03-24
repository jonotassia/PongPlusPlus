#include <iostream>
#include <SDL.h>
#include <string>

#include "render.h"
#include "game.h"
#include "paddle.h"
#include "ball.h"

Renderer::~Renderer() {
	SDL_DestroyRenderer(pRenderer_);
	SDL_DestroyWindow(pWindow_);
	SDL_Quit();
}

void Renderer::setColorScheme() {
	switch (pGame_->color_scheme_) {
		case(Game::PowerUps::kNone): SDL_SetRenderDrawColor(pRenderer_, 0xFF, 0xFF, 0xFF, 0xFF); break;
		case(Game::PowerUps::kFire): SDL_SetRenderDrawColor(pRenderer_, 0xFA, 0x8D, 0x22, 0xFF); break;
		case(Game::PowerUps::kIce): SDL_SetRenderDrawColor(pRenderer_, 0x27, 0xB7, 0xDE, 0xFF); break;
		case(Game::PowerUps::kSun): SDL_SetRenderDrawColor(pRenderer_, 0xF6, 0xFA, 0x17, 0xFF); break;
		case(Game::PowerUps::kShadow): SDL_SetRenderDrawColor(pRenderer_, 0x67, 0x4E, 0xA7, 0xFF); break;
		case(Game::PowerUps::kSniper): SDL_SetRenderDrawColor(pRenderer_, 0xF6, 0xFA, 0x17, 0xFF); break;
	}
}

void Renderer::drawNet() {
	SDL_RenderDrawLine(pRenderer_, WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
}

void Renderer::drawScore() {
	// TODO: Add score renderer above screen (consider a second window that is born of an abstract screen class)
}

void Renderer::drawBall() {
	// Create SDL rectangle
	SDL_Rect ball;
	ball.x = pGame_->getBall()->position_x;
	ball.y = pGame_->getBall()->position_y;
	ball.w = pGame_->getBall()->width;
	ball.h = pGame_->getBall()->height;

	// Render a filled rectangle
	SDL_RenderFillRect(pRenderer_, &ball);
}

void Renderer::drawPaddles() {
	// Create SDL rectangles for each paddle
	SDL_Rect paddle_one;
	paddle_one.x = pGame_->getPaddleOne()->position_x;
	paddle_one.y = pGame_->getPaddleOne()->position_y;
	paddle_one.w = pGame_->getPaddleOne()->width;
	paddle_one.h = pGame_->getPaddleOne()->height;

	SDL_Rect paddle_two;
	paddle_two.x = pGame_->getPaddleTwo()->position_x;
	paddle_two.y = pGame_->getPaddleTwo()->position_y;
	paddle_two.w = pGame_->getPaddleTwo()->width;
	paddle_two.h = pGame_->getPaddleTwo()->height;

	// Render a filled rectangle
	SDL_RenderFillRect(pRenderer_, &paddle_one);
	SDL_RenderFillRect(pRenderer_, &paddle_two);
}

void Renderer::drawVictoryScreen() {
	//TODO: Draw a victory screen indicating who won and the final score
}

void Renderer::drawScreen() {
	// Clear the window to black
	SDL_SetRenderDrawColor(pRenderer_, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(pRenderer_);

	// Rendering for each frame below. Color set based on current power up
	setColorScheme();
	drawNet();
	drawPaddles();
	drawBall();
	drawScore();

	// Present the backbuffer
	SDL_RenderPresent(pRenderer_);
}