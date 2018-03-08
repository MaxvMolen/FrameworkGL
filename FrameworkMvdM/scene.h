/**
* @file scene.h
*
* @brief The Scene header file.
*/

#ifndef SCENE_H
#define SCENE_H

#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <string>
#include <vector>

#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtx/euler_angles.hpp>

#include <FrameworkMvdM/sprite.h>
/// @brief The Scene class
class Scene
{
public:
	Scene();///< @brief Constructor of an Scene
	virtual ~Scene();///< @brief Destructor of an Scene

	/// @brief update this Scene. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime) = 0;
	/// @brief add an child to this Entity
	/// @param child The Entity you want to add as a child to this Entity
	/// @return void

private:

};


#endif /* SCENE_H */
