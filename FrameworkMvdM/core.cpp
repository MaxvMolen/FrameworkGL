/**
* @file core.cpp
*
* @brief The Core cpp file.
*/

#include <FrameworkMvdM/core.h>

Core::Core()
{
	_deltaTime = 0;
}

Core::~Core()
{

}

void Core::run(Scene* scene)
{
	// update our _deltaTime
	_calculateDeltaTime();

	// Update camera instance in Scene
	scene->camera()->update((float)_deltaTime);

	// Update Scene (and recursively all children)
	scene->update((float)_deltaTime);

	// Render Scene
	_renderer.renderScene(scene);

	// user clicked the 'close' button in the window
	if (glfwWindowShouldClose(_renderer.window()) == 1) { scene->stop(); }
}

double Core::_calculateDeltaTime()
{
	static double lastTime = glfwGetTime();
	double startTime = glfwGetTime();
	_deltaTime = startTime - lastTime;
	lastTime = startTime;

	return _deltaTime;
}

void Core::cleanup()
{

}


void Core::showFrameRate(float numesecs)
{

}



