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

	for (unsigned int i = 0; i<GLFW_KEY_LAST; i++) {
		_keys[i] = false;
		_keysUp[i] = false;
		_keysDown[i] = false;
	}
	for (unsigned int i = 0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		_mouse[i] = false;
		_mouseUp[i] = false;
		_mouseDown[i] = false;
	}
}

Input::~Input()
{
	
}

void Input::updateInput(GLFWwindow* window) {
	_window = window;

	glfwPollEvents();

	// 32-97 = ' ' to '`'
	for (unsigned int i = 32; i<97; i++) {
		_handleKey(i);
	}
	// Func + arrows + esc, etc
	for (unsigned int i = 255; i<GLFW_KEY_LAST; i++) {
		_handleKey(i);
	}
	//  window size
	glfwGetWindowSize(_window, &_windowWidth, &_windowHeight);

	glfwGetCursorPos(_window, &_mouseX, &_mouseY);

	// Fix cursor position if window size is different from the set resolution
	_mouseX = ((float)SWIDTH / _windowWidth) * _mouseX;
	_mouseY = ((float)SHEIGHT / _windowHeight) * _mouseY;
	// mouse buttons
	for (unsigned int i = 0; i<GLFW_MOUSE_BUTTON_LAST; i++) {
		_handleMouse(i);
	}
}

void Input::_handleMouse(unsigned int key) {
	if (glfwGetMouseButton(_window, key) == GLFW_PRESS) {
		if (_mouse[key] == false) { // if first time pressed down
			_mouse[key] = true;
			_mouseDown[key] = true;
			//std::cout << "DOWN: " << key << std::endl;
		}
		else {
			// not the first time this is pressed
			// keys[key] is still true;
			_mouseDown[key] = false;
		}
	}

	if (glfwGetMouseButton(_window, key) == GLFW_RELEASE) {
		if (_mouse[key] == true) { // still pressed
			_mouse[key] = false;
			_mouseUp[key] = true;
			//std::cout << "UP: " << key << std::endl;
		}
		else {
			_mouseUp[key] = false;
		}
	}
}

void Input::_handleKey(unsigned int key) {
	if (glfwGetKey(_window, key) == GLFW_PRESS) {
		if (_keys[key] == false) { // if first time pressed down
			_keys[key] = true;
			_keysDown[key] = true;
			//std::cout << "DOWN: " << key << std::endl;
		}
		else {
			// not the first time this is pressed
			// keys[key] is still true;
			_keysDown[key] = false;
		}
	}

	if (glfwGetKey(_window, key) == GLFW_RELEASE) {
		if (_keys[key] == true) { // still pressed
			_keys[key] = false;
			_keysUp[key] = true;
			//std::cout << "UP: " << key << std::endl;
		}
		else {
			_keysUp[key] = false;
		}
	}
}
