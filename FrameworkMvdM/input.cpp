/**
* @file input.cpp
*
* @brief The Input cpp file.
*/

#include <FrameworkMvdM/input.h>

Input::Input()
{
	_window = NULL;

	_windowWidth = 0;
	_windowHeight = 0;

	_mouseX = 0;
	_mouseY = 0;
}

Input::~Input()
{
	
}

void Input::updateInput(GLFWwindow* window) {
	_window = window;

	glfwPollEvents();

	//  window size
	glfwGetWindowSize(_window, &_windowWidth, &_windowHeight);

	glfwGetCursorPos(_window, &_mouseX, &_mouseY);

	// Fix cursor position if window size is different from the set resolution
	_mouseX = ((float)SWIDTH / _windowWidth) * _mouseX;
	_mouseY = ((float)SHEIGHT / _windowHeight) * _mouseY;
}

void Input::_handleKey(unsigned int key) {
	if (glfwGetKey(_window, key) == GLFW_PRESS) {
	
	}

	if (glfwGetKey(_window, key) == GLFW_RELEASE) {
	
	}
}
