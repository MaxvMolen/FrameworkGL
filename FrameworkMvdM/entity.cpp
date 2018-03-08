/**
* @file entity.cpp
*
* @brief The Entity cpp file.
*/

#include <FrameworkMvdM/entity.h>

Entity::Entity()
{

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

}
//
void Entity::removeChild(Entity* child) {

}
//
Entity* Entity::getChild(unsigned int i) {
	return NULL;
}
//
void Entity::addSprite(const std ::string& filename) {
	//this->addSprite(filename, 0.5f, 0.5f);
}

void Entity::addSprite(const std::string& filename, float pivotx, float pivoty) {
	//deleteSprite();
	//_sprite = new Sprite();
	//_sprite->setupSprite(filename, 0.5f, 0.5f);
}



