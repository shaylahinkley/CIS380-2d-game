#include "BananaHandler.hpp"
#include "Banana.hpp"

BananaHandler::BananaHandler(int totalBananas) {
	for (int i = 0; i < totalBananas; i++)
		bananas.emplace_back(new Banana());

	bItr = bananas.begin();
}

BananaHandler::~BananaHandler() { }

void BananaHandler::update(double delta) { }

Banana* BananaHandler::at(int index) {
	return bananas.at(index);
}

int BananaHandler::size() {
	return bananas.size();
}