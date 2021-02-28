#include "Engine.hpp"
#include "Sprite.hpp"
#include <string>

Sprite::Sprite(std::string file) {
	surface = IMG_Load(file.c_str());
	if (surface == NULL) {
		SDL_Log("Unable to load image.");
		exit(1);
	}

	
}

Sprite::Sprite(SDL_Surface* surf) {
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surf);
	if (texture == NULL) {
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}
}

//must add updateable to updatable vector in scene
//must add drawable to drawable vector in scene
//add destructors