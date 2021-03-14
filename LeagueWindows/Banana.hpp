#ifndef			__HPP__BANANA__
#define			__HPP__BANANA__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"
#include "Score.hpp"
#include <random>

class Banana : public Sprite {
	public:
		Banana();
		//Banana(SDL_Surface* surface);
		~Banana();
		void update(double delta);
		void bruise();
		void peel();
		bool isBruised();
		bool isPeeled();
		void timer(int time);
		void monkeyPositionX(int x);
		void monkeyPositionY(int y);
		void setScorePtr(Score* score);

	private:
		Vector3 velocity;
		std::random_device rd;
		std::mt19937 rng;
		std::uniform_int_distribution<int> uni;
		bool bruised;
		bool peeled;
		unsigned int lastTime;
		int timeout;
		int monkeyX;
		int monkeyY = 695;
		Score* scorePtr;

		SDL_Surface* surf_bruised;
		SDL_Surface* surf_peeled;
		SDL_Texture* tex_bruised;
		SDL_Texture* tex_peeled;
};

#endif