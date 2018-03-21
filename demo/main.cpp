/**
* @file main.cpp
*
* @brief The Main header file.
*/

#include <FrameworkMvdM/core.h>

#include <Demo/demo.h>

/// @brief main entry point
int main( void )
{
	// Core instance
	Core core;
	//list of scenes
	std::vector<CoreScene*> myscenes;
	myscenes.push_back(new Demo());
	int s = myscenes.size();

	CoreScene* scene = myscenes[0];
	int scenecounter = 0;
	int running = 1;
	while (running) {
		scenecounter = scene->activescene;
		if (scenecounter > s-1) { scenecounter = 0; scene->activescene = 0; }
		if (scenecounter < 0) { scenecounter = s-1; scene->activescene = s-1; }
		scene = myscenes[scenecounter];
		core.run(scene); // update and render the current scene
		//std::cout << scene << std::endl; // current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!scene->isRunning()) { running = 0; } // check status of Scene every frame
	}

	//delete all scenes
	for (int i = 0; i < s; i++) {
		delete myscenes[i];
		myscenes[i] = NULL;
	}
	myscenes.clear();
	
	
	/*
	//core.cleanup(); // cleanup ResourceManager (Textures + Meshes, but not Shaders)
	delete myscene; // delete Scene and everything in it from the heap to make space for next Scene
	
	// No need to explicitly clean up the core.
	// As a local var, core will go out of scope and destroy Renderer->ResourceManager.
	// ResourceManager destructor also deletes Shaders.
	*/
	return 0;
}