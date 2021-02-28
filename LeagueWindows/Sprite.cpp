#include "Engine.hpp"
#include "Sprite.hpp"
#include <string>

/*
* Constructor that takes the path to the file, converts to a surface, then to a texture
*/
Sprite::Sprite(std::string file, int x, int y){
	surface = IMG_Load(file.c_str());
	if (surface == NULL) {
		SDL_Log("Unable to load image.");
		exit(1);
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if (texture == NULL) {
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}
	rect->x = x;
	rect->y = y;
	rect->w = surface->w;
	rect->h = surface->h;

}

/*
* Constructor that takes a surface and converts to a texture
*/
Sprite::Sprite(SDL_Surface* surf, int x, int y){
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surf);
	if (texture == NULL) {
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}
	rect->x = x;
	rect->y = y;
	rect->w = surface->w;
	rect->h = surface->h;
}

/*
* Destructor that destroys the texture and surface
*/
Sprite::~Sprite() {
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Sprite::update(double delta) {

}

/*
* Draws the sprite
*/
void Sprite::draw() {
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}
