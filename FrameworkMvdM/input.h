/**
* @file input.h
*
* @brief The Input header file.
*/

#ifndef INPUT_H
#define INPUT_H

#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <string>
#include <vector>

#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtx/euler_angles.hpp>

//#include <FrameworkMvdM/sprite.h>
/// @brief The Input class
class Input
{
public:
	Input();///< @brief Constructor of an Input
	virtual ~Input();///< @brief Destructor of an Input

	/// @brief update this Input. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime) = 0;

private:

};


#endif INPUT_H
