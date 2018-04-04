/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

Scene01::Scene01() : CoreScene()
{
	entity = new Entity();
	entity->addSprite("assets/rgba.tga");
	entity->position = glm::vec3(200.0f, 100.0f, 0.0f);
	this->addChild(entity);

	basicEntity = new BasicEntity();
	basicEntity->addSprite("assets/kingkong.tga");
	basicEntity->position = glm::vec3(700, 100, 0.0f);
	this->addChild(basicEntity);
}

Scene01::~Scene01()
{
	delete entity;
	delete basicEntity;
}


void Scene01::update(float deltaTime) {

}
