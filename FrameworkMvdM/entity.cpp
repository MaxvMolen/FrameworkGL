/**
* @file entity.cpp
*
* @brief The Entity cpp file.
*/
//#include <iostream>

#include <FrameworkMvdM/entity.h>

int Entity::_nextGuid = 0;

Entity::Entity()
{
	_guid = _nextGuid;
	_nextGuid++;

	_parent = NULL;

	_sprite = NULL;
}

Entity::~Entity()
{
	deleteSprite();
}
//
void Entity::update(float deltaTime) {

}
//
void Entity::addChild(Entity* child) {
	if (child->_parent != NULL) {
		child->_parent->removeChild(child);
	}
	child->_parent = this;
	this->_children.push_back(child);
}
//
void Entity::removeChild(Entity* child) {
	std::vector<Entity*>::iterator it = _children.begin();
	while (it != _children.end()) {
		if ((*it)->_guid == child->_guid) {
			child->_parent = NULL;
			it = _children.erase(it);
		}
		else {
			++it;
		}
	}
}
//
Entity* Entity::getChild(unsigned int i) {
	if (i < _children.size()) {
		return _children[i];
	}
	return NULL;
}
//
void Entity::addSprite(Sprite* spr) {
	deleteSprite();
	//_sprite = new Sprite();
	*_sprite = *spr;
}
//
void Entity::addSprite(const std ::string& filename) {
	this->addSprite(filename, 0.5f, 0.5f);
}
//
void Entity::addSprite(const std::string& filename, float pivotx, float pivoty) {
	deleteSprite();
	//_sprite = new Sprite();
	//_sprite->setupSprite(filename, pivotx, pivoty , 1.0f, 1.0f, DEFAULTFILTER, DEFAULTWRAP);
}
//
void Entity::addSprite(const std::string& filename, float pivotx, float pivoty, int filter, int wrap) {
	deleteSprite();
	//_sprite = new Sprite();
	//_sprite->setupSprite(filename, pivotx, pivoty , 1.0f, 1.0f, filter, wrap);
}



