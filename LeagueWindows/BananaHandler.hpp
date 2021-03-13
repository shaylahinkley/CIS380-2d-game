#ifndef			__HPP__BANANAHANDLER__
#define			__HPP__BANANAHANDLER__

#include <vector>
#include "Banana.hpp"

class BananaHandler : public UGameObject {
	public:
		BananaHandler(int totalBananas);
		~BananaHandler();
		void update(double delta);
		int size();
		Banana* at(int index);

	private:
		std::vector<Banana*> bananas;
		std::vector<Banana*>::iterator bItr;
};

#endif