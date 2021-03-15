#include "Engine.hpp"
#include "Banana.hpp"
#include "Monkey.hpp"
#include "Score.hpp"
#include <random>
#include <stdlib.h>

Banana::Banana() : Sprite("../assets/banana.png") {
	rng = std::mt19937(rd());
	uni = std::uniform_int_distribution<int>(32, 992);
	position.setX(uni(rng));
	position.setY(-50);
	velocity.setX(std::uniform_int_distribution<int>(-200, 200)(rng));
	velocity.setY(0);
	velocity.setZ(0);
	bruised = false;
	peeled = false;

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


void Banana::monkeyPositionX(int x) {
	monkeyX = x;
}

void Banana::update(double delta) {

	if (SDL_TICKS_PASSED(SDL_GetTicks(), timeout)) {
		position.setY(position.getY() + velocity.getY() * delta);
		position.setX(position.getX() + velocity.getX() * delta);

		if (!peeled)
			velocity.setY(velocity.getY() + 200 * delta); // gravity

		if (position.getX() > 1024 - rect->w || position.getX() < 0) {
			velocity.setX(-velocity.getX());
		}
		if (position.getY() > 768 - rect->h) {
			if (!bruised && !peeled) {
				velocity.setY(-(velocity.getY() - (velocity.getY() / 4)));

				bruise();
			}
			if (bruised && lastTime > 10) {
				position.setY(768 - rect->h);
				velocity.setX(0);
				velocity.setY(0);

				peel();
			}
		}

		//A scuffed "timer?" that does remove the banana after a few(5 or so) seconds
		if (peeled || bruised) {
			lastTime++;
		}

		if (peeled && lastTime > 211) {
			Banana::~Banana();
		}

		//catch the banana and set the score and make a noise
		if ((monkeyX - position.getX()) > -80 && (monkeyX - position.getX()) < 5 && (monkeyY - position.getY()) > -15 && (monkeyY- position.getY()) < 10) {

			int i, count = SDL_GetNumAudioDevices(0);
			if (count < 1) {
				SDL_Log("Audio error. %s", SDL_GetError());
			}
			for (i = 0; i < count; ++i) {
				SDL_Log("Audio device %d: %s", i, SDL_GetAudioDeviceName(i, 0));
			}
			SDL_AudioSpec wavSpec;
			Uint32 length;
			Uint8* buffer;
			SDL_LoadWAV("../assets/hit.wav", &wavSpec, &buffer, &length);
			SDL_AudioDeviceID device = SDL_OpenAudioDevice(NULL, 0, &wavSpec, NULL, 0);
			int success = SDL_QueueAudio(device, buffer, length);
			SDL_Log("Audio success: %d %s", success, SDL_GetError());
			SDL_PauseAudioDevice(device, 0);

			if (isBruised()) {
				scorePtr->setScore(scorePtr->getScore() + 5);
			}
			else if (isPeeled()) {
				
			}
			else {
				scorePtr->setScore(scorePtr->getScore() + 10);
			}
			Banana::~Banana();
		}
	}
}

void Banana::bruise() {
	lastTime = 0;
	bruised = true;
	surface = surf_bruised;
	texture = tex_bruised;
}

void Banana::peel() {
	lastTime = 0;
	bruised = false;
	peeled = true;
	surface = surf_peeled;
	texture = tex_peeled;
}

bool Banana::isBruised() {
	return bruised;
}

bool Banana::isPeeled() {
	return peeled;
}

void Banana::timer(int time) {
	timeout = time;
}

void Banana::setScorePtr(Score* score) {
	scorePtr = score;
}
