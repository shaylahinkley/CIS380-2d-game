#include "Engine.hpp"
#include "BananaOne.hpp"
#include <random>

BananaOne::BananaOne() : Sprite("../assets/banana.png", 0, 0) {

	rng = std::mt19937(rd());
	uni = std::uniform_int_distribution<int>(0, 700);
	position.setX(uni(rng));
	position.setY(0);
	velocity.setX(0);
	velocity.setY(100);
	velocity.setZ(0);
}

void BananaOne::update(double delta) {
	position.setY(position.getY() + velocity.getY() * delta);
}

