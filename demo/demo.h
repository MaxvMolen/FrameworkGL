/**
* @file demo.h
*
* @brief The Demo header file.
*/

#ifndef DEMO_H
#define DEMO_H


// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <iostream>
#include <cstdio>
#include <string>
#include <vector>

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <glm/gtx/euler_angles.hpp>

#include <Demo/corescene.h>

/// @brief The Demo class
class Demo : public CoreScene
{
public:
	Demo();///< @brief Constructor of Demo
	virtual ~Demo();///< @brief Destructor of Demo

	/// @brief update this Demo. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime);

private:
	/// @brief the pencils sprite in the scene
	BasicEntity* pencilss;
	Sprite* pencils;
	/// @brief the kingkong sprite in the scene
	Sprite* kingkong;
	/// @brief the rgba sprite in the scene
	Sprite* rgba;
};


#endif DEMO_H 
