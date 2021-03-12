#include <SDL.h>
#include <SDL_image.h>
#include "Interfaces.hpp"
#include "Utility.hpp"
#include "Sprite.hpp"
#include <random>

class Banana : public Sprite {
	public:
		Banana();
		~Banana();
		void update(double delta);
		bool isBruised();
		bool isPeeled();

	private:
		Vector3 velocity;
		std::random_device rd;
		std::mt19937 rng;
		std::uniform_int_distribution<int> uni;
		bool bruised;
		bool peeled;
		unsigned int lastTime;

		SDL_Surface* surf_bruised;
		SDL_Surface* surf_peeled;
		SDL_Texture* tex_bruised;
		SDL_Texture* tex_peeled;
};
