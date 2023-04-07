#include <iostream>
#include <SDL.h>
#include <SDL_ttf.h>
#include <string>

#include "render.h"
#include "definitions.h"
#include "game.h"
#include "paddle.h"
#include "ball.h"

Renderer::Renderer() {
	if (pWindow_ == nullptr || pRenderer_ == nullptr) {
		throw std::logic_error("Unable to obtain SDL Window/Renderer");
	}
	SDL_SetWindowBordered(pWindow_, SDL_TRUE);
}

Renderer::~Renderer() {
	SDL_DestroyRenderer(pRenderer_);
	SDL_DestroyWindow(pWindow_);
	SDL_Quit();
}

void Renderer::setColorScheme() {
	switch (pGame_->getSession()->active_powerup) {
		case(PowerUps::kNone): SDL_SetRenderDrawColor(pRenderer_, 0xFF, 0xFF, 0xFF, 0xFF); break;
		case(PowerUps::kFire): SDL_SetRenderDrawColor(pRenderer_, 0xFA, 0x8D, 0x22, 0xFF); break;
		case(PowerUps::kIce): SDL_SetRenderDrawColor(pRenderer_, 0x27, 0xB7, 0xDE, 0xFF); break;
		case(PowerUps::kSun): SDL_SetRenderDrawColor(pRenderer_, 0xF6, 0xFA, 0x17, 0xFF); break;
		case(PowerUps::kShadow): SDL_SetRenderDrawColor(pRenderer_, 0x67, 0x4E, 0xA7, 0xFF); break;
		case(PowerUps::kConfusion): SDL_SetRenderDrawColor(pRenderer_, 0xFF, 0x00, 0xFF, 0xFF); break;
	}
}

void Renderer::drawNet() {
	SDL_RenderDrawLine(pRenderer_, WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
}

void Renderer::drawScore(int score, int x, int y) {
	TTF_Init();
	
	// Set a font style and size
	TTF_Font* font = TTF_OpenFont("C:\\Windows\\Fonts\\Candara.ttf", 24);
	if (!font) {
		printf(TTF_GetError());
	}

	// Specify text color
	SDL_Color White = { 255, 255, 255 };

	// as TTF_RenderText_Solid could only be used on
	// SDL_Surface then you have to create the surface first
	SDL_Surface* surfaceMessage =
		TTF_RenderText_Solid(font, std::to_string(score).c_str(), White);

	// Convert to texture
	SDL_Texture* Message = SDL_CreateTextureFromSurface(pRenderer_, surfaceMessage);

	// Create a rect that functions as a text box
	SDL_Rect Message_rect;
	Message_rect.x = x;
	Message_rect.y = y;
	Message_rect.w = 100; 
	Message_rect.h = 100; 

	// Render the message into the text box
	SDL_RenderCopy(pRenderer_, Message, NULL, &Message_rect);

	SDL_FreeSurface(surfaceMessage);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(font);
	TTF_Quit();
}

void Renderer::drawBall() {
	// Create SDL rectangle
	SDL_Rect ball;
	ball.x = pGame_->getSession()->getBall()->position_x;
	ball.y = pGame_->getSession()->getBall()->position_y;
	ball.w = pGame_->getSession()->getBall()->width;
	ball.h = pGame_->getSession()->getBall()->height;

	// Render a filled rectangle
	SDL_RenderFillRect(pRenderer_, &ball);
}

void Renderer::drawPaddles() {
	// Create SDL rectangles for each paddle
	SDL_Rect paddle_one;
	paddle_one.x = pGame_->getSession()->getPaddleOne()->position_x;
	paddle_one.y = pGame_->getSession()->getPaddleOne()->position_y;
	paddle_one.w = pGame_->getSession()->getPaddleOne()->width;
	paddle_one.h = pGame_->getSession()->getPaddleOne()->height;

	SDL_Rect paddle_two;
	paddle_two.x = pGame_->getSession()->getPaddleTwo()->position_x;
	paddle_two.y = pGame_->getSession()->getPaddleTwo()->position_y;
	paddle_two.w = pGame_->getSession()->getPaddleTwo()->width;
	paddle_two.h = pGame_->getSession()->getPaddleTwo()->height;

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
	drawScore(pGame_->getPlayerOne()->points, WINDOW_WIDTH / 4, WINDOW_HEIGHT * 0.10);
	drawScore(pGame_->getPlayerTwo()->points, WINDOW_WIDTH - WINDOW_WIDTH / 3, WINDOW_HEIGHT * 0.10);

	// Present the backbuffer
	SDL_RenderPresent(pRenderer_);
}