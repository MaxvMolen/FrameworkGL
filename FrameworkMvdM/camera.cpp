/**
* @file camera.cpp
*
* @brief The Camera cpp file.
*/
#include <FrameworkMvdM/camera.h>

Camera::Camera() {
	position = glm::vec3(0, 0, 5);

	right = glm::vec3(1, 0, 0);
	up = glm::vec3(0, 1, 0);
}

Camera::~Camera()
{

}

void Camera::update(float deltaTime) {
	// View matrix
	_viewMatrix = glm::lookAt(
		position, // Camera is at (xpos,ypos,5), in World Space
		position + glm::vec3(0, 0, -5), // and looks towards Z
		up  // Head is up (set to 0,-1,0 to look upside-down)
	);
}
