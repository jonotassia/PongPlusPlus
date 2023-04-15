#include <iostream>
#include "SDL2/SDL.h"
#include "SDL2/SDL_ttf.h"
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

// Sets color based on current active powerup
void Renderer::setColorScheme(PowerUps powerup) {
	switch (powerup) {
		case(PowerUps::kNone): SDL_SetRenderDrawColor(pRenderer_, white.r, white.g, white.b, white.a); break;
		case(PowerUps::kFire): SDL_SetRenderDrawColor(pRenderer_, fire.r, fire.g, fire.b, fire.a); break;
		case(PowerUps::kIce): SDL_SetRenderDrawColor(pRenderer_, ice.r, ice.g, ice.b, ice.a); break;
		case(PowerUps::kSun): SDL_SetRenderDrawColor(pRenderer_, sun.r, sun.g, sun.b, sun.a); break;
		case(PowerUps::kShadow): SDL_SetRenderDrawColor(pRenderer_, shadow.r, shadow.g, shadow.b, shadow.a); break;
		case(PowerUps::kConfusion): SDL_SetRenderDrawColor(pRenderer_, confusion.r, confusion.g, confusion.b, confusion.a); break;
	}
}

/*
Draws background if appropriate. In general, background will just be black except in the below scenarios:
	* Shadow ball: Opponents half of the screen turns same color as the ball
	* Sun ball: Entire screen turns similar color to ball
*/
void Renderer::drawBackground() {
	// Returns if no powerup active
	if (pGame_->getSession()->active_powerup == PowerUps::kNone) {
		return;
	}
	
	switch (pGame_->getSession()->active_powerup) {
		case PowerUps::kShadow:
			// Set the color scheme to shadow
			SDL_SetRenderDrawColor(pRenderer_, shadow.r, shadow.g, shadow.b, shadow.a);
			
			// Define rectangle to shade other players half
			SDL_Rect opp_paddle_zone;
			opp_paddle_zone.y = 0;
			opp_paddle_zone.h = WINDOW_HEIGHT;

			// Depending on who activated the powerup, set the correct half of the screen
			if (pGame_->getSession()->powerup_owner == pGame_->getSession()->getPaddleOne()) {
				opp_paddle_zone.x = WINDOW_WIDTH - Paddle::init_width * 2;
				opp_paddle_zone.w = Paddle::init_width * 2;
			}
			else {
				opp_paddle_zone.x = 0;
				opp_paddle_zone.w = Paddle::init_width * 2;
			}
			// Fill rectangle
			SDL_RenderFillRect(pRenderer_, &opp_paddle_zone);
			break;

		case PowerUps::kSun:
			// Set the color scheme to white
			SDL_SetRenderDrawColor(pRenderer_, white.r, white.g, white.b, 0xAA);

			// Create a rectangle the size of the screen and fill it
			SDL_Rect field;
			field.w = WINDOW_WIDTH;
			field.h = WINDOW_HEIGHT;
			field.y = 0;
			field.x = 0;

			SDL_RenderFillRect(pRenderer_, &field);
			break;

		default:
			break;
	}
}

// Draws the net along the midline of the field of play.
void Renderer::drawNet() {
	SDL_RenderDrawLine(pRenderer_, WINDOW_WIDTH / 2, 0, WINDOW_WIDTH / 2, WINDOW_HEIGHT);
}

// Uses SDL_TTF to draw the score on the screen.
void Renderer::drawScore(int score, int x, int y) {
	TTF_Init();
	
	// Set a font style and size
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	TTF_Font* font = TTF_OpenFont("C:\\Windows\\Fonts\\Candara.ttf", 24);
	#else
	TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-R.ttf", 24);
	#endif

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

// Draws the powerup indicators at the top of the screen. This tells users whether they have a powerup available or not.
void Renderer::drawPowerups() {
	// Create SDL rectangles for each paddle
	SDL_Rect powerup_one;
	powerup_one.x = WINDOW_WIDTH / 2 - Paddle::init_height;
	powerup_one.y = 0;
	powerup_one.w = Paddle::init_height;
	powerup_one.h = Paddle::init_width;

	SDL_Rect powerup_two;
	powerup_two.x = WINDOW_WIDTH / 2;
	powerup_two.y = 0;
	powerup_two.w = Paddle::init_height;
	powerup_two.h = Paddle::init_width;

	// Render a filled rectangle with color from player one if powerup available. Otherwise, make it hollow.
	setColorScheme(pGame_->getPlayerOne()->selected_powerup);
	if (pGame_->getSession()->getPaddleOne()->powerup_available) {
		SDL_RenderFillRect(pRenderer_, &powerup_one);
	}
	else {
		SDL_RenderDrawRect(pRenderer_, &powerup_one);
	}

	// Render a filled rectangle with color from player two if powerup available. Otherwise, make it hollow.
	setColorScheme(pGame_->getPlayerTwo()->selected_powerup);
	if (pGame_->getSession()->getPaddleTwo()->powerup_available) {
		SDL_RenderFillRect(pRenderer_, &powerup_two);
	}
	else {
		SDL_RenderDrawRect(pRenderer_, &powerup_two);
	}
	
}

// Uses SDL TTF to draw a victory screen once a player wins.
void Renderer::drawVictoryScreen(Player* winner, Player* loser) {
	TTF_Init();

	// Set a font style and size
	#if defined(WIN32) || defined(_WIN32) || defined(__WIN32) && !defined(__CYGWIN__)
	TTF_Font* font = TTF_OpenFont("C:\\Windows\\Fonts\\Candara.ttf", 24);
	#else
	TTF_Font* font = TTF_OpenFont("/usr/share/fonts/truetype/abyssinica/AbyssinicaSIL-R.ttf", 24);
	#endif

	if (!font) {
		printf(TTF_GetError());
	}

	// Specify text color
	SDL_Color White = { 255, 255, 255 };

	// Write winner text
	std::string message_string = "Player " + std::to_string(static_cast<int>(winner->player_num)) + " Wins";

	// as TTF_RenderText_Solid could only be used on
	// SDL_Surface then you have to create the surface first
	SDL_Surface* winnerMessage =
		TTF_RenderText_Solid(font, message_string.c_str(), White);

	// Convert to texture
	SDL_Texture* Message = SDL_CreateTextureFromSurface(pRenderer_, winnerMessage);

	// Create a rect that functions as a text box
	SDL_Rect Message_rect;
	Message_rect.x = WINDOW_WIDTH / 4;
	Message_rect.y = WINDOW_HEIGHT / 2;
	Message_rect.w = WINDOW_WIDTH / 2;
	Message_rect.h = WINDOW_HEIGHT / 4;

	// Render the message into the text box
	SDL_RenderCopy(pRenderer_, Message, NULL, &Message_rect);
	SDL_RenderPresent(pRenderer_);

	// Sleep for a couple seconds to show score
	SDL_Delay(3000);

	SDL_FreeSurface(winnerMessage);
	SDL_DestroyTexture(Message);
	TTF_CloseFont(font);
	TTF_Quit();
}

/*
Bundles together render functions to abstract away from gameplay loop. Includes:
	* Setting the render color
	* Drawing the background and powerup indicators
	* Drawing the game objects
	* Presenting the render
*/
void Renderer::drawScreen() {
	// Clear the window to black
	SDL_SetRenderDrawColor(pRenderer_, 0x0, 0x0, 0x0, 0xFF);
	SDL_RenderClear(pRenderer_);

	// Rendering for each frame below.

	// Color-independant of current powerup
	drawBackground();
	drawPowerups();

	// Color set based on current active power up
	setColorScheme(pGame_->getSession()->active_powerup);
	drawNet();
	drawPaddles();
	drawBall();
	drawScore(pGame_->getPlayerOne()->points, WINDOW_WIDTH / 4, WINDOW_HEIGHT * 0.10);
	drawScore(pGame_->getPlayerTwo()->points, WINDOW_WIDTH - WINDOW_WIDTH / 3, WINDOW_HEIGHT * 0.10);

	// Present the backbuffer
	SDL_RenderPresent(pRenderer_);
}