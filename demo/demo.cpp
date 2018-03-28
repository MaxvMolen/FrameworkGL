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

//#include <FrameworkMvdM/camera.h> // not the solution
#include <FrameworkMvdM/renderer.h>
#include <FrameworkMvdM/entity.h>
#include <FrameworkMvdM/sprite.h>
#include <FrameworkMvdM/camera.h>
#include <demo/basicentity.h>

#include <demo/scene01.h>

int main(void)
{
	Renderer renderer(1280, 720);

	Sprite* pencils = new Sprite("assets/pencils.tga");
	Sprite* kingkong = new Sprite("assets/kingkong.tga");
	Sprite* rgba = new Sprite("assets/rgba.tga");
	Sprite* rgba2 = new Sprite("assets/rgba.tga");

	Entity* entity = new Entity();
	//BasicEntity* entity = new BasicEntity();
	//entity->addSprite("assets/rgba.tga");

	//Camera* camera = new Camera();

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
		renderer.renderSprite(rgba2, 100, 200, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(rgba, renderer.width() / 2, renderer.height() / 2, 3.0f, 3.0f, rot_z);
		rot_z += 0.13f * deltaTime;

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
	delete rgba2;

	// entity
	delete entity;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();
}
