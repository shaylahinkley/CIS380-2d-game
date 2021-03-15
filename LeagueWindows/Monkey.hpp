#ifndef			__HPP__MONKEY__
#define			__HPP__MONKEY__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"
#include "BananaHandler.hpp"

class Monkey : public Sprite {
	public:
		Monkey();
		void update(double delta);	
		void left(double delta);
		void right(double delta);
		void slowdown(double delta);
		bool isIdle();
		void nanerHandler(BananaHandler* n);
		void setScorePtr(Score* score);
		
	private:
		Vector3 velocity;
		int speed;
		bool idle;
		BananaHandler* handle;
		Score* scorePtr;

		SDL_Surface* surf_catch1;
		SDL_Surface* surf_catch2;
		SDL_Surface* surf_catch3;
		SDL_Surface* surf_catch4;
		SDL_Texture* tex_catch1;
		SDL_Texture* tex_catch2;
		SDL_Texture* tex_catch3;
		SDL_Texture* tex_catch4;
};

#endif
