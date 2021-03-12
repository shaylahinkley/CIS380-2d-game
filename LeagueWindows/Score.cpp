#include "Engine.hpp"
#include "Score.hpp"
#include <SDL_ttf.h>
#include <random>
#include <string>

Score::Score() {
	stick = TTF_OpenFont("../assets/coded.ttf", 20);
	if (stick == NULL) {
		SDL_Log("No font. %s", TTF_GetError());
	}
	color.r = 50;
	color.g = 50;
	color.b = 50;

	scoreVar = 0;

	std::string scoreText = "Score: " + std::to_string(scoreVar);
	const char* strScore = scoreText.c_str();
	surface = TTF_RenderText_Solid(stick, strScore, color);
	if (surface == NULL) {
		SDL_Log("Can't create text. %s", SDL_GetError());
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if (texture == NULL) {
		SDL_Log("Can't create texture. %s", SDL_GetError());
	}
	rect->x = 0;
	rect->y = 0;
	rect->w = surface->w;
	rect->h = surface->h;
	rng = std::mt19937(rd());
	uni = std::uniform_int_distribution<int>(50, 255);
}

void Score::setScore(int n) {
	scoreVar = n;
}

Score::~Score() {
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Score::update(double delta) {
	color.r = uni(rng);
	color.b = uni(rng);
	color.g = uni(rng);

	std::string scoreText = "Score: " + std::to_string(scoreVar);
	const char* strScore = scoreText.c_str();
	surface = TTF_RenderText_Solid(stick, strScore, color);
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);

}

void Score::draw() {
	SDL_Rect* dst = new SDL_Rect();
	position.setY(25);
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}