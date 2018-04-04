/**
* @file camera.h
*
* @brief The Camera header file.
*/
#ifndef CAMERA_H
#define CAMERA_H

#include <GL/glew.h>
#include <glfw3.h>

#include <glm/glm.hpp>
#include <glm/ext.hpp>
#include <glm/gtc/matrix_transform.hpp>

/// @brief The Camera class
class Camera
{
public:
	Camera();///< @brief Constructor of an Camera
	virtual ~Camera();///< @brief Destructor of an Camera

	glm::vec3 position;
	glm::vec3 rotation;

	/// @brief update this Camera. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime);

	glm::mat4 getViewMatrix() { return _viewMatrix; };

	glm::vec3 getCursor() { return cursor; };

private:

	glm::mat4 _viewMatrix;

	//glm::vec3 offset;

	//glm::vec3 direction; ///< @brief The up vector of the Camera.
	glm::vec3 up; ///< @brief The up vector of the Camera.
	glm::vec3 right; ///< @brief The right vector of the Camera.

	glm::vec3 cursor;
};

#endif /* CAMERA_H */
