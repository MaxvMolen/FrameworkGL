/**
* @file demo.cpp
*
* @brief This is where functions of the framework are tested
*/

#include <fstream>
#include <sstream>

#include <Demo/demo.h>

//rotation speed of rgba
float rot_z = 0.0f;

Demo::Demo() : CoreScene()
{
	// set textures 
	//pencils = new Sprite("assets/pencils.tga");
	//kingkong = new Sprite("assets/kingkong.tga");
	//rgba = new Sprite("assets/rgba.tga");
}

Demo::~Demo()
{
	// Clean up
	delete pencils;
	delete kingkong;
	delete rgba;
	//glfwTerminate();
}

void Demo::update(float deltaTime) {

	/*do {
		this->addSprite(pencils)
		// Clear the screen
		glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
		// Compute the ViewMatrix from keyboard and mouse input (see: camera.h/cpp)
		renderer.camera()->computeMatricesFromInputs(renderer.window());
		//computeMatricesFromInputs(renderer.window());
		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		renderer.renderSprite(pencils, 400, 300, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(kingkong, 900, 400, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(rgba, renderer.width() / 2, renderer.height() / 2, 3.0f, 3.0f, rot_z);

		rot_z += 0.3f * deltaTime;// * deltaTime to have the same rotationspeed at any fps

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();
	}
	
	//close game if the user presses escape
	while (glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE) != GLFW_PRESS &&
	glfwWindowShouldClose(renderer.window()) == 0 );
	*/
}
