#ifndef			__HPP__SPRITE__
#define			__HPP__SPRITE__

#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"

class Sprite : public DUGameObject {
	public:
		Sprite(std::string file);
		Sprite(SDL_Surface* surf);

	private:
};
#endif