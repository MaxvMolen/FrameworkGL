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

#include <FrameworkMvdM/renderer.h>
#include <FrameworkMvdM/entity.h>
#include <FrameworkMvdM/sprite.h>
#include <FrameworkMvdM/camera.h>
#include <demo/basicentity.h>

#include <FrameworkMvdM/core.h>
#include <demo/scene01.h>

int main(void)
{
	Renderer renderer(1280, 720);

	//****Main****//
	// Core instance
	Core core;
	//list of scenes
	std::vector<CoreScene*> myscenes;
	//myscenes.push_back(new Scene01());
	int s = myscenes.size();

	CoreScene* scene = myscenes[0];
	int scenecounter = 0;
	int running = 1;
	/*
	while (running) {
		scenecounter = scene->activescene;
		if (scenecounter > s - 1) { scenecounter = 0; scene->activescene = 0; }
		if (scenecounter < 0) { scenecounter = s - 1; scene->activescene = s - 1; }
		scene = myscenes[scenecounter];
		core.run(scene); // update and render the current scene
		core.showFrameRate(5); // show framerate in output every n seconds
		if (!scene->isRunning()) { running = 0; } // check status of Scene every frame
	}
	*/
	//****Main****//

	//sprites
	Sprite* pencils = new Sprite("assets/pencils.tga");
	Sprite* kingkong = new Sprite("assets/kingkong.tga");
	Sprite* rgba = new Sprite("assets/rgba.tga");
	//entity
	Entity* entity = new Entity();

	// add sprite to entity and change its position
	entity->addSprite("assets/pencils.tga");
	entity->position.x = 500;
	entity->position.y = 75;

	float rot_z = 0.0f;

	do {
		// glfwGetTime is called only once, the first time this function is called
		static double lastTime = glfwGetTime();

		// Compute time difference between current and last frame
		double currentTime = glfwGetTime();
		float deltaTime = float(currentTime - lastTime);

		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		computeMatricesFromInputs(renderer.window());
		//camera->computeMatricesFromInputs(renderer.window());

		//glm::vec3 cursor = getCursor(); // from Camera
		//printf("(%f,%f)\n",cursor.x, cursor.y);
		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		renderer.renderSprite(pencils, 400, 300, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(kingkong, 900, 400, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(rgba, renderer.width() / 2, renderer.height() / 2, 3.0f, 3.0f, rot_z);
		rot_z += 0.13f * deltaTime; // rotatate sprite rgba

		// render entity
		renderer.renderEntity(entity);

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

		// For the next frame, the "last time" will be "now"
		lastTime = currentTime;
	} // Check if the ESC key was pressed or the window was closed
	while (glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
		glfwWindowShouldClose(renderer.window()) == 0);

	// cleanup

	// sprites
	delete pencils;
	delete kingkong;
	delete rgba;

	// entity
	delete entity;

	//****Main****//
		//delete all scenes
	for (int i = 0; i < s; i++) {
		delete myscenes[i];
		myscenes[i] = NULL;
	}
	myscenes.clear();
	//****Main****//

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}
