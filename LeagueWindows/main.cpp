#include "Engine.hpp"
#include "Monkey.hpp"
#include "HUD.hpp"
#include "Score.hpp"
#include "BananaHandler.hpp"
#include <SDL.h>

int main(int argc, char** argv){
	SDL_Log("Starting up, with following arguments:");
	for(int i=0; i<argc; ++i){
		SDL_Log("%d = %s", i, argv[i]);
	}

	// Create a scene
	Scene sceneOne;
	// Create an engine.  Must happen early, creates the renderer.
	Engine engine(1024, 768);
	Engine* ePtr = &engine;

	// Make a monkey and add to scene. Should update and draw.
	Monkey* monkey = new Monkey();
	sceneOne.addUpdateable(monkey);
	sceneOne.addDrawable(monkey);
	auto monkey_left = [monkey, ePtr](double delta) {
		switch (ePtr->getEvent().type) {
			case SDL_KEYDOWN:
				monkey->left(delta);
				break;
			case SDL_KEYUP:
				monkey->slowdown(delta);
				break;
		}
	};
	auto monkey_right = [monkey, ePtr](double delta) {
		switch (ePtr->getEvent().type) {
			case SDL_KEYDOWN:
				monkey->right(delta);
				break;
			case SDL_KEYUP:
				monkey->slowdown(delta);
				break;
		}
	};
	sceneOne.addKeyEvent( SDLK_a, monkey_left );
	sceneOne.addKeyEvent( SDLK_d, monkey_right );

	BananaHandler* naner_handler = new BananaHandler(100);
	sceneOne.addUpdateable(naner_handler);
	for (int i = 0; i < naner_handler->size(); i++) {
		sceneOne.addUpdateable(naner_handler->at(i));
		sceneOne.addDrawable(naner_handler->at(i));
	}

	// Add the HUD
	HUD* h = new HUD();
	sceneOne.addUpdateable(h);
	sceneOne.addDrawable(h);

	//add the Score
	Score* s = new Score();
	sceneOne.addUpdateable(s);
	sceneOne.addDrawable(s);

	// Set the scene in the engine
	engine.setScene(&sceneOne);
	
	// Get the engine running.
	engine.run();

	return 0;
}
