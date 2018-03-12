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

	/// @brief update this Entity. This function is Pure virtual. User MUST implement this in subclass. 
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime) = 0;

	//transform
	glm::vec3 position;
	glm::vec3 rotation;
	glm::vec3 scale;
	
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
	/// @brief add an Sprite to this Entity by Sprite*
	/// @param spr A pointer to a sprite
	/// @return void
	void addSprite(Sprite* spr);
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
	/// @brief add an Sprite to this Entity
	/// @param filename the filename of the image that you want to add
	/// @param pivotx the x component of the pivotpoint
	/// @param pivoty the y component of the pivotpoint
	/// @param filter The filter
	/// @param wrap The Wrapping
	/// @return void
	void addSprite(const std::string& filename, float pivotx, float pivoty, int filter, int wrap);

	// line

	// world position,rotation and scale
	/// @brief get the worldposition of this Entity
	/// @return glm::vec3 _worldposition
	glm::vec3 worldposition() { return _worldposition; };
	/// @brief get the worldrotation of this Entity
	/// @return glm::vec3 _worldrotation
	glm::vec3 worldrotation() { return _worldrotation; };
	/// @brief get the worldscale of this Entity
	/// @return glm::vec3 _worldscale
	glm::vec3 worldscale() { return _worldscale; };

	/// @brief get the guid of this Entity
	/// @return int _guid
	int guid() { return _guid; };
	/// @brief get the parent of this Entity
	/// @return entity* _parent
	Entity* parent() { return _parent; };

	friend class Renderer;

protected:

	// world position,rotation and scale of this Entity
	glm::vec3 _worldposition;
	glm::vec3 _worldrotation;
	glm::vec3 _worldscale;

private:
	
	int _guid; ///< @brief The _guid of this entity
	static int _nextGuid; ///< @brief The _nextGuid of this entity
	
	// parent
	Entity* _parent; ///< @brief The _parent of this entity
	std::vector<Entity*> _children; ///< @brief The _children of this entity

	// sprite
	Sprite* _sprite; ///< @brief The _sprite of this entity

	// line
	//Line* _line; ///< @brief The _line of this entity

	/// @brief delete the sprite of this Entity
	/// @return void
	void deleteSprite() {
		if (_sprite != NULL) {
			delete _sprite;
			_sprite = NULL;
		}
	}

	/// @brief delete the line of this Entity
	/// @return void
	/*void deleteLine() {
		if (_line != NULL) {
			delete _line;
			_line = NULL;
		}
	}*/
};


#endif /* ENTITY_H */
