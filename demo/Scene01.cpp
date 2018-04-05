/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

Scene01::Scene01() : CoreScene()
{
	rgba = new BasicEntity();
	rgba->addSprite("assets/rgba.tga");
	rgba->position = glm::vec3(200, 200, 0);
	this->addChild(rgba);

	kingkong = new BasicEntity();
	kingkong->addSprite("assets/kingkong.tga");
	kingkong->position = glm::vec3(400, 200, 0);
	this->addChild(kingkong);

	pencils = new BasicEntity();
	pencils->addSprite("assets/pencils.tga");
	pencils->position = glm::vec3(600, 200, 0);
	this->addChild(pencils);
}

Scene01::~Scene01()
{
	delete rgba;
	delete kingkong;
	delete pencils;
}

void Scene01::update(float deltaTime) {

}
