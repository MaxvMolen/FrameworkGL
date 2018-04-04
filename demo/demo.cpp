/**
* @file demo.cpp
*
* @brief This is where functions of the framework are tested
*/

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <fstream>
#include <sstream>

#include <FrameworkMvdM/core.h>
#include <demo/scene01.h>

int main(void)
{
	// Core instance
	Core core;
	//list of scenes
	std::vector<CoreScene*> myscenes;
	myscenes.push_back(new Scene01());
	int s = myscenes.size();

	CoreScene* scene = myscenes[0];
	int scenecounter = 0;
	int running = 1;
	
	while (running) {
		scenecounter = scene->activescene;
		if (scenecounter > s - 1) { scenecounter = 0; scene->activescene = 0; }
		if (scenecounter < 0) { scenecounter = s - 1; scene->activescene = s - 1; }
		scene = myscenes[scenecounter];
		core.run(scene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!scene->isRunning()) { running = 0; } // check status of Scene every frame
	}
	
	//delete all scenes
	for (int i = 0; i < s; i++) {
		delete myscenes[i];
		myscenes[i] = NULL;
	}
	myscenes.clear();

	// Close OpenGL window and terminate GLFW
	return 0;
}
