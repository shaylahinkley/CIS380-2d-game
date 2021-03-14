#ifndef			__HPP__BANANAHANDLER__
#define			__HPP__BANANAHANDLER__

#include <vector>
#include "Banana.hpp"
#include "Score.hpp"

class BananaHandler : public UGameObject {
	public:
		BananaHandler(int totalBananas);
		~BananaHandler();
		void update(double delta);
		int size();
		Banana* at(int index);
		float timer;
		void monkeyX(int x);
		void setScorePtr(Score* score);

	private:
		std::vector<Banana*> bananas;
		std::vector<Banana*>::iterator bItr;
		int monkeyPosition;
		Score* scorePtr;
};

#endif