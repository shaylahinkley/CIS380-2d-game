#include "Engine.hpp"
#include "Monkey.hpp"
#include "Passer.hpp"
#include "BananaHandler.hpp"

Monkey::Monkey() : Sprite("../assets/monkey.png"){
	position.setY(700);
	velocity.setX(0);
	velocity.setY(0);
	velocity.setZ(0);
	speed = 500;
	idle = true;

	surf_catch1 = IMG_Load("../assets/monkeyCatch1.png");
	tex_catch1 = SDL_CreateTextureFromSurface(Engine::getRenderer(), surf_catch1);
	surf_catch2 = IMG_Load("../assets/monkeyCatch2.png");
	tex_catch2 = SDL_CreateTextureFromSurface(Engine::getRenderer(), surf_catch2);
	surf_catch3 = IMG_Load("../assets/monkeyCatch3.png");
	tex_catch3 = SDL_CreateTextureFromSurface(Engine::getRenderer(), surf_catch3);
	surf_catch4 = IMG_Load("../assets/monkeyCatch4.png");
	tex_catch4 = SDL_CreateTextureFromSurface(Engine::getRenderer(), surf_catch4);
}

void Monkey::update(double delta) {
	position.setX(position.getX() + velocity.getX() * delta);
	position.setY(position.getY() + velocity.getY() * delta);
	if (position.getX() > 1024 - rect->w)
		position.setX(1024 - rect-> w);
	else if (position.getX() < 0)
		position.setX(0);

	if (idle)
		velocity.setX(velocity.getX() - (velocity.getX() / 8));

	handle->monkeyX(position.getX());

	if (scorePtr->getScore() >= 10 && scorePtr->getScore() < 50) {
		surface = surf_catch1;
		texture = tex_catch1;
	}
	else if (scorePtr->getScore() >= 50 && scorePtr->getScore() < 200) {
		surface = surf_catch2;
		texture = tex_catch2;
	}
	else if (scorePtr->getScore() >= 200 && scorePtr->getScore() < 500) {
		surface = surf_catch3;
		texture = tex_catch3;
	}
	else if (scorePtr->getScore() >= 500) {
		surface = surf_catch4;
		texture = tex_catch4;
	}
}

void Monkey::nanerHandler(BananaHandler* n) {
	handle = n;
}

void Monkey::left(double delta){
	idle = false;
	velocity.setX(-speed);

}
void Monkey::right(double delta){
	idle = false;
	velocity.setX(speed);
}

void Monkey::slowdown(double delta) {
	idle = true;
	velocity.setX(0);
}

bool Monkey::isIdle() {
	return idle;
}

void Monkey::setScorePtr(Score* score) {
	scorePtr = score;
}
