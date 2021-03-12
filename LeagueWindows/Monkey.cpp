#include "Engine.hpp"
#include "Monkey.hpp"

Monkey::Monkey(): Sprite("../assets/monkey.png"){
	position.setY(700);
	velocity.setX(0);
	velocity.setY(0);
	velocity.setZ(0);
}

void Monkey::update(double delta){
	// So we stop getting the compiler warning for now.
}

void Monkey::left(double delta){
	if (position.getX() < 0) {
		position.setX(0);
	}
	else {
		position.setX(position.getX() - 15);
	}
}
void Monkey::right(double delta){
	if (position.getX() > 1024 - rect->w) {
		position.setX(1024);
	}
	else {
		position.setX(position.getX() + 15);
	}
}
