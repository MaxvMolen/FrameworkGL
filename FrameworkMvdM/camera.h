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
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

/*class Camera {
public:	
	Camera();///< @brief Constructor of an Entity
	virtual ~Camera();///< @brief Destructor of an Entity
	*/
	glm::mat4 getViewMatrix();
	glm::vec3 getCursor();

	void computeMatricesFromInputs(GLFWwindow* window);
	/*
	/// @brief update this Entity. This function is Pure virtual. User MUST implement this in subclass. 
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime) = 0;
	

	

private:

};*/
#endif
