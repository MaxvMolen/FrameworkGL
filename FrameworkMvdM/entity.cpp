/**
* @file entity.cpp
*
* @brief The Entity cpp file.
*/
#include <FrameworkMvdM/entity.h>

Entity::Entity()
{
	_parent = NULL;

	// position of entity
	position = glm::vec3(0.0f, 0.0f, 0.0f);
	rotation = glm::vec3(0.0f, 0.0f, 0.0f);
	scale = glm::vec3(1.0f, 1.0f, 1.0f);

	_sprite = NULL;
}

Entity::~Entity()
{
	deleteSprite();
}

void Entity::addChild(Entity* child) {
	if (child->_parent != NULL) {
		child->_parent->removeChild(child);
	}
	child->_parent = this;
	this->_children.push_back(child);
}

void Entity::removeChild(Entity* child) {
	std::vector<Entity*>::iterator it = _children.begin();
	while (it != _children.end()) {
		if ((*it) == child) {
			child->_parent = NULL;
			it = _children.erase(it);
		}
		else {
			++it;
		}
	}
}

Entity* Entity::getChild(unsigned int i) {
	if (i < _children.size()) {
		return _children[i];
	}
	return NULL;
}

void Entity::addSprite(const std ::string& filename) {
	deleteSprite();
	_sprite = new Sprite(filename);
	_sprite->setupSprite(filename);
}
