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

class Camera {
public:	
	Camera();///< @brief Constructor of an Entity
	virtual ~Camera();///< @brief Destructor of an Entity
	
	glm::vec3 position; ///< @brief The position of the cursor
	glm::vec3 rotation; ///< @brief The rotation of the cursor
	glm::vec3 cursor = glm::vec3(0, 0, 0); ///< @brief The position of the cursor

	/// @brief update this Entity. This function is Pure virtual. User MUST implement this in subclass. 
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime);

	/// @brief get the viewMatrix of the Camera.
	/// @return glm::mat4 _viewMatrix
	glm::mat4 viewMatrix() { return _viewMatrix; };

	/// @brief get the getCursor of the Camera.
	/// @return glm::vec3 _getCursor
	//glm::vec3 getCursor() { return _getCursor; };

	void computeMatricesFromInputs(GLFWwindow* window);

private:
	glm::mat4 _viewMatrix; ///< @brief The viewMatrix of the Camera
	glm::vec3 _getCursor(); ///< @brief The cursor of the Camera
};
#endif
