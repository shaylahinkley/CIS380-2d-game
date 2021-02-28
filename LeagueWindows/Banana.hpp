#ifndef			__HPP__BANANA__
#define			__HPP__BANANA__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"

class Banana : public DUGameObject {
	public:
		Banana();
		~Banana();
		void update(double delta);
		void draw();	
		void left(double delta);
		void right(double delta);
		void up(double delta);
		void down(double delta);
	private:
		Vector3 velocity;

};

#endif
