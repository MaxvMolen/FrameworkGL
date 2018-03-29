/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

Scene01::Scene01() : CoreScene()
{
	entity = new BasicEntity();
	entity->addSprite("assets/rgba.tga");
	entity->position = glm::vec3(200.0f, 100.0f, 0.0f);
}

Scene01::~Scene01()
{
	delete entity;
}


void Scene01::update(float deltaTime) {

}
