// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <common/renderer.h>
#include <common/camera.h>
#include <common/sprite.h>

int main( void )
{
	Renderer renderer(1280, 720);

	Sprite* pencils = new Sprite("assets/pencils.tga");
	Sprite* kingkong = new Sprite("assets/kingkong.tga");
	Sprite* rgba = new Sprite("assets/rgba.tga");

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

		// print position of the mouse on screen
		//glm::vec3 cursor = getCursor(); // from Camera
		//printf("(%f,%f)\n",cursor.x, cursor.y);

		// Render all Sprites (Sprite*, xpos, ypos, xscale, yscale, rotation)
		renderer.renderSprite(pencils, 400, 300, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(kingkong, 900, 400, 1.0f, 1.0f, 0.0f);
		renderer.renderSprite(rgba, renderer.width()/2, renderer.height()/2, 3.0f, 3.0f, rot_z);
		rot_z += 0.3f * deltaTime;// * deltaTime to have the same rotationspeed no matter what fps you have
		// the default rotation speed of the rgba image = 0.03f

		// Swap buffers
		glfwSwapBuffers(renderer.window());
		glfwPollEvents();

		// For the next frame, the "last time" will be "now"
		lastTime = currentTime;
	} // Check if the ESC key was pressed or the window was closed
	while( glfwGetKey(renderer.window(), GLFW_KEY_ESCAPE ) != GLFW_PRESS &&
		   glfwWindowShouldClose(renderer.window()) == 0 );

	delete pencils;
	delete kingkong;
	delete rgba;

	// Close OpenGL window and terminate GLFW
	glfwTerminate();

	return 0;
}
