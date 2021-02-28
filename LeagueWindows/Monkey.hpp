#ifndef			__HPP__MONKEY__
#define			__HPP__MONKEY__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"

class Monkey : public DUGameObject {
	public:
		Monkey();
		~Monkey();
		void update(double delta);
		void draw();	
		void left(double delta);
		void right(double delta);
		//void up(double delta);
		//void down(double delta);
	private:
		Vector3 velocity;

};

#endif
