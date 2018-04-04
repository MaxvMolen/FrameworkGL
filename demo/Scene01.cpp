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

	sceneEntity = new Entity();
	sceneEntity->addSprite("assets/pencils.tga");
	sceneEntity->position = glm::vec3(0.0f, 0.0f, 0.0f);
	this->addChild(sceneEntity);
}

Scene01::~Scene01()
{
	delete entity;
	delete sceneEntity;
}


void Scene01::update(float deltaTime) {

}
