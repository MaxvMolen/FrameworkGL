/**
* @file line.h
*
* @brief The Line header file.
*/

#ifndef LINE_H
#define LINE_H

#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <string>
#include <vector>

#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtx/euler_angles.hpp>

//#include <FrameworkMvdM/sprite.h>
/// @brief The Line class
class Line
{
public:
	Line();///< @brief Constructor of an Line
	virtual ~Line();///< @brief Destructor of an Line

	/// @brief update this Line. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime) = 0;

private:

};


#endif LINE_H
