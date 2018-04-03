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
#include <algorithm>

#include <glm/glm.hpp>
#include <glm/gtx/matrix_decompose.hpp>

#include <FrameworkMvdM/sprite.h>
#include <FrameworkMvdM/line.h>
#include <FrameworkMvdM/input.h>

/// @brief The Entity class is the Base class for the elements in your Scene.
class Entity
{
public:
	Entity();///< @brief Constructor of an Entity
	virtual ~Entity();///< @brief Destructor of an Entity

	//transform // the position,rotation and scale of this Entity
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	
	/// @brief update this Entity. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	//virtual void update(float deltaTime) = 0;

	// children
	/// @brief add an child to this Entity
	/// @param child The Entity you want to add as a child to this Entity
	/// @return void
	void addChild(Entity* child);
	/// @brief remove an child from this Entity
	/// @param child The child you want to remove from this Entity
	/// @return void
	void removeChild(Entity* child);
	/// @brief get Entity from the list of children
	/// @param i The id of the Entity you want to get
	/// @return Entity* child
	Entity* getChild(unsigned int i);
	/// @brief get list of children
	/// @return std::vector<Entity*>& children
	const std::vector<Entity*>& children() { return _children; };

	// sprites
	/// @brief get the Sprite of this Entity
	/// @return Sprite* _sprite
	Sprite* sprite() { return _sprite; };
	/// @brief add an Sprite to this Entity
	/// @param filename the filename of the image that you want to add
	/// @return void
	void addSprite(const std::string& filename);
	/// @brief add an sprite to this Entity
	/// @param filename the filename of the image that you want to add
	/// @param pivotx the x component of the pivotpoint
	/// @param pivoty the y component of the pivotpoint
	/// @return void
	void addSprite(const std::string& filename, float pivotx, float pivoty);

	/// @brief get the parent of this Entity
	/// @return entity* _parent
	Entity* parent() { return _parent; };

	// world position,rotation and scale
	/// @brief get the worldposition of this Entity
	/// @return glm::vec3 _worldposition
	//glm::vec3 worldposition() { return _worldposition; };
	/// @brief get the worldrotation of this Entity
	/// @return glm::vec3 _worldrotation
	//glm::vec3 worldrotation() { return _worldrotation; };
	/// @brief get the worldscale of this Entity
	/// @return glm::vec3 _worldscale
	//glm::vec3 worldscale() { return _worldscale; };

	/// @brief get a pointer to the Input
	/// @return Input* a pointer to the Input
	Input* input() { return _input; };

	//friend class Renderer;

protected:

private:

	// parent
	Entity* _parent; ///< @brief The _parent of this entity
	std::vector<Entity*> _children; ///< @brief The _children of this entity

	// sprite
	Sprite* _sprite; ///< @brief The _sprite of this entity

	// input
	Input* _input; ///< @brief The Input

	/// @brief delete the sprite of this Entity
	/// @return void
	void deleteSprite() {
		if (_sprite != NULL) {
			delete _sprite;
			_sprite = NULL;
		}
	}
};


#endif /* ENTITY_H */
