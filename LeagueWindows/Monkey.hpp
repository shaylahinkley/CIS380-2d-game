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
		
	private:
		Vector3 velocity;
		int speed;
		bool idle;
		BananaHandler* handle;
};

#endif
