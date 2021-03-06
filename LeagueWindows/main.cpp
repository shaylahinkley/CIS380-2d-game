#include "Engine.hpp"
#include "Monkey.hpp"
#include "Banana.hpp"
#include "HUD.hpp"
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

	// Make a monkey and add to scene. Should update and draw.
	Monkey* monkey = new Monkey();
	sceneOne.addUpdateable(monkey);
	sceneOne.addDrawable(monkey);
	//auto b_up = [b](double delta) { b->up(delta); };
	//auto b_down = [b](double delta) { b->down(delta); };
	auto monkey_left = [monkey](double delta) { monkey->left(delta); };
	auto monkey_right = [monkey](double delta) { monkey->right(delta); };
	//one.addKeyEvent( SDLK_w, b_up );
	sceneOne.addKeyEvent( SDLK_a, monkey_left );
	sceneOne.addKeyEvent( SDLK_d, monkey_right );
	//one.addKeyEvent( SDLK_s, b_down );

	//Add a banana
	Banana* banana = new Banana();
	sceneOne.addUpdateable(banana);
	sceneOne.addDrawable(banana);

	// Add the HUD
	HUD* h = new HUD();
	sceneOne.addUpdateable(h);
	sceneOne.addDrawable(h);

	// Set the scene in the engine
	engine.setScene(&sceneOne);
	
	// Get the engine running.
	engine.run();

	return 0;
}
