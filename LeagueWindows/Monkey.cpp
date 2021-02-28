#include "Engine.hpp"
#include "Monkey.hpp"

Monkey::Monkey(){
	surface = IMG_Load("../assets/monkey1.png");
	if( surface == NULL ){
		SDL_Log("Unable to load banana.");
		exit(1);
	}
	texture = SDL_CreateTextureFromSurface(Engine::getRenderer(), surface);
	if( texture == NULL ){
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}
	rect->x = 0;
	rect->y = 0;
	rect->w = surface->w;
	rect->h = surface->h;
	position.setY(700);
	velocity.setX(0);
	velocity.setY(0);
	velocity.setZ(0);
}

Monkey::~Monkey(){
	SDL_DestroyTexture(texture);
	SDL_FreeSurface(surface);
}

void Monkey::update(double delta){
	// So we stop getting the compiler warning for now.
	position.setX(position.getX() + velocity.getX() * delta);
	position.setY(position.getY() + velocity.getY() * delta);
	if(position.getX() > 1024-rect->w || position.getX() < 0){
		velocity.setX(- velocity.getX());
	}
	if(position.getY() > 768-rect->h || position.getY() < 0){
		velocity.setY(- velocity.getY());
	}
}

void Monkey::draw(){
	SDL_Rect* dst = new SDL_Rect();
	dst->x = position.getX();
	dst->y = position.getY();
	dst->w = rect->w;
	dst->h = rect->h;
	SDL_RenderCopy(Engine::getRenderer(), texture, NULL, dst);
}

void Monkey::left(double delta){
	if(velocity.getX() > -200){
		velocity.setX(velocity.getX() - 10);
	}
}
void Monkey::right(double delta){
	if(velocity.getX() < 200){
		velocity.setX(velocity.getX() + 10);
	}
}
/*
void Monkey::up(double delta){
	if(velocity.getY() > -200 ){
		velocity.setY(velocity.getY() - 10);
	}
}
void Monkey::down(double delta){
	if(velocity.getY() < 200 ){
		velocity.setY(velocity.getY() + 10);
	}
}
*/
