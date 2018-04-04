/**
* @file camera.cpp
*
* @brief The Camera cpp file.
*/
#include <FrameworkMvdM/camera.h>

Camera::Camera() {
	position = glm::vec3(0, 0, 5);
	//rotation = glm::vec3(0, 0, 0);
	cursor = glm::vec3(0, 0, 0);

	//direction = glm::vec3(0, 0, -5);
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

/*
void Camera::update(float deltaTime)
{
	// Direction vector: Spherical coordinates to Cartesian coordinates conversion
	direction = glm::vec3(
		cos(rotation.x) * sin(rotation.y),
		sin(rotation.x),
		cos(rotation.x) * cos(rotation.y)
	);
	//_direction = glm::vec3(0, 0, -5);

	// Right vector
	right = glm::vec3(
		sin(rotation.y - 1.5707963267948966192313216916398),
		0,
		cos(rotation.y - 1.5707963267948966192313216916398)
	);
	right = glm::rotateZ(right, rotation.z*(float)57.295779513082320876798154814105); // rotateZ() in Degrees
																 //_right = glm::vec3(1, 0, 0);

																 // Up vector
	up = glm::cross(right, direction);
	//_up = glm::vec3(0, 1, 0);

	glm::vec3 pos = glm::vec3(position.x, position.y, position.z);
	glm::vec3 offset = glm::vec3(offset.x, offset.y, offset.z);

	// View matrix
	_viewMatrix = glm::lookAt(
		pos - offset, // Camera is at (xpos,ypos,1), in World Space
		pos - offset + direction, // and looks towards Z
		up  // Head is up
	);
}
*/
