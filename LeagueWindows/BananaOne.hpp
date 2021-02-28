#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"
#include <random>

class BananaOne : public Sprite {
	public:
		BananaOne();
		void update(double delta);
	private:
		Vector3 velocity;
		std::random_device rd;
		std::mt19937 rng;
		std::uniform_int_distribution<int> uni;

};
