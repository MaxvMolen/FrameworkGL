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
/*
class Camera {
public:	
	Camera();///< @brief Constructor of an Entity
	virtual ~Camera();///< @brief Destructor of an Entity
	*/
	/// @brief get the viewMatrix of the Camera.
	/// @return glm::mat4 _getViewMatrix
	glm::mat4 getViewMatrix();// { return _getViewMatrix; };
	glm::vec3 getCursor();

	void computeMatricesFromInputs(GLFWwindow* window);
	/*
	/// @brief update this Entity. This function is Pure virtual. User MUST implement this in subclass. 
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime) = 0;
	
private:
	glm::mat4 _getViewMatrix(); ///< @brief The viewMatrix of the Camera
	//glm::vec3 _getCursor(); ///< @brief The cursor of the Camera
};*/
#endif
