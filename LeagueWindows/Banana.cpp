#include "Engine.hpp"
#include "Banana.hpp"
#include <random>
#include <stdlib.h>

Banana::Banana() : Sprite("../assets/banana.png") {
	rng = std::mt19937(rd());
	uni = std::uniform_int_distribution<int>(200, 624);
	position.setX(uni(rng));
	position.setY(0);
	velocity.setX(std::uniform_int_distribution<int>(-200, 200)(rng));
	velocity.setY(0);
	velocity.setZ(0);
	bruised = false;
	peeled = false;
	lastTime = 0;

	/* Load alternate textures (this is is probably inefficient) */

	// bruised texture
	surf_bruised = IMG_Load("../assets/bananaBruised.png");
	if (surf_bruised == NULL) {
		SDL_Log("Unable to load image.");
		exit(1);
	}
	tex_bruised = SDL_CreateTextureFromSurface(Engine::getRenderer(), surf_bruised);
	if (tex_bruised == NULL) {
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}

	// peeled texture
	surf_peeled = IMG_Load("../assets/bananaPeel.png");
	if (surf_peeled == NULL) {
		SDL_Log("Unable to load image.");
		exit(1);
	}
	tex_peeled = SDL_CreateTextureFromSurface(Engine::getRenderer(), surf_peeled);
	if (tex_peeled == NULL) {
		SDL_Log("-----> HAVE YOU CREATED THE ENGINE YET? <-----");
		SDL_Log("Unable to create texture. %s", SDL_GetError());
	}
}

Banana::~Banana() {
	
}

void Banana::update(double delta) {
	position.setY(position.getY() + velocity.getY() * delta);
	position.setX(position.getX() + velocity.getX() * delta);

	velocity.setY(velocity.getY() + 200 * delta); // gravity

	if (position.getX() > 1024 - rect -> w || position.getX() < 0) {
		velocity.setX(-velocity.getX());
	}
	if (position.getY() > 768 - rect -> h) {
		if (!bruised) {
			velocity.setY(-(velocity.getY() - (velocity.getY() / 2)));
			bruised = true;
			surface = surf_bruised;
			texture = tex_bruised;
		}
		else {
			velocity.setX(0);
			velocity.setY(0);

			peeled = true;

			surface = surf_peeled;
			texture = tex_peeled;

			
			
		}
	}
	//A scuffed "timer?" that does remove the banana after a few(5 or so) seconds
	lastTime++;
	if (lastTime > 211) {
		Banana::~Banana();
	}
}

bool Banana::isBruised() {
	return bruised;
}

bool Banana::isPeeled() {
	return peeled;
}