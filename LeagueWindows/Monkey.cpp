#include "Engine.hpp"
#include "Monkey.hpp"

Monkey::Monkey(): Sprite("../assets/monkey.png"){
	position.setY(700);
	velocity.setX(0);
	velocity.setY(0);
	velocity.setZ(0);
	speed = 500;
	idle = true;
}

void Monkey::update(double delta){
	position.setX(position.getX() + velocity.getX() * delta);
	position.setY(position.getY() + velocity.getY() * delta);
	if (position.getX() > 1024 - rect->w)
		position.setX(1024 - rect-> w);
	else if (position.getX() < 0)
		position.setX(0);

	if (idle)
		velocity.setX(velocity.getX() - (velocity.getX() / 8));
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
	//velocity.setX(0);
}

bool Monkey::isIdle() {
	return idle;
}
