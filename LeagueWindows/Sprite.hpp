#ifndef			__HPP__SPRITE__
#define			__HPP__SPRITE__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include <string>

class Sprite : public DUGameObject {
	public:
		Sprite();
		Sprite(std::string file);
		Sprite(SDL_Surface* surf);
		SDL_Surface* surface;
		SDL_Texture* texture;
		~Sprite();
		void update(double delta);
		void draw();

	private:

	friend class Collision;
};
#endif