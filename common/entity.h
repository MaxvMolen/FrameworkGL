/**
* @file entity.h
*
* @brief The Entity header file.
*/

#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <string>
#include <vector>

#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtx/euler_angles.hpp>

#include <common/sprite.h>
/// @brief The Entity class is the Base class for the elements in your Scene.
class Entity
{
public:
	Entity();///< @brief Constructor of an Entity
	virtual ~Entity();///< @brief Destructor of an Entity

	/// @brief update this Entity. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime) = 0;
	/// @brief add an child to this Entity
	/// @param child The Entity you want to add as a child to this Entity
	/// @return void
	void addChild(Entity* child);
	/// @brief remove an child from this Entity
	/// @param child The child you want to remove from this Entity
	/// @return void
	void removeChild(Entity* child);

private:

};


#endif /* ENTITY_H */
