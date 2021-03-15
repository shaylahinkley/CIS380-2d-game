#include "Engine.hpp"
#include "Score.hpp"
#include <SDL_ttf.h>
#include <random>
#include <string>
#include <SDL_mixer.h>

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

int Score::getScore() {
	return scoreVar;
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

void Score::scoreSound() {
	//Initialize SDL
	if (SDL_Init(SDL_INIT_VIDEO | SDL_INIT_AUDIO) < 0)
	{
		printf("SDL could not initialize! SDL Error: %s\n", SDL_GetError());
		success = false;
	}

	//Initialize SDL_mixer
	if (Mix_OpenAudio(44100, MIX_DEFAULT_FORMAT, 2, 2048) < 0)
	{
		printf("SDL_mixer could not initialize! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	hit = Mix_LoadWAV("../assets/hit.wav");
	if (hit == NULL)
	{
		printf("Failed to load low sound effect! SDL_mixer Error: %s\n", Mix_GetError());
		success = false;
	}
	Mix_PlayChannel(-1, hit, 0);

}