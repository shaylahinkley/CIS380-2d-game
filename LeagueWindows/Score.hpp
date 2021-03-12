#ifndef			__HPP__SCORE__
#define			__HPP__SCORE__

#include <SDL.h>
#include <SDL_image.h>
#include <SDL_ttf.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <random>

class Score : public DUGameObject {
public:
	Score();
	~Score();
	void setScore(int n);
	void update(double delta);
	void draw();
private:
	TTF_Font* stick;
	SDL_Color color;
	int elapsed;
	int scoreVar;
	std::random_device rd;
	std::mt19937 rng;
	std::uniform_int_distribution<int> uni;

};

#endif