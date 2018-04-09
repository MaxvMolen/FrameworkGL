/**
* @file scene02.cpp
*
* @brief The Scene02 cpp file.
*/

#include <Demo/scene02.h>

Scene02::Scene02() : CoreScene()
{
	rgba = new BasicEntity();
	rgba->addSprite("assets/rgba.tga");
	rgba->position = glm::vec3(200, 200, 0);
	this->addChild(rgba);

	kingkong = new BasicEntity();
	kingkong->addSprite("assets/rgba.tga");
	kingkong->position = glm::vec3(400, 200, 0);
	//kingkong->scale = glm::vec3(1, 1, 1);
	this->addChild(kingkong);

	pencils = new BasicEntity();
	pencils->addSprite("assets/rgba.tga");
	pencils->position = glm::vec3(600, 200, 0);
	this->addChild(pencils);
}

Scene02::~Scene02()
{
	delete rgba;
	delete kingkong;
	delete pencils;
}

void Scene02::update(float deltaTime) {

}
