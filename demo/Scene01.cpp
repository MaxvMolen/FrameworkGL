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
	//kingkong->scale = glm::vec3(1, 1, 1);
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
	//left each release key
	if (input()->getKeyUp(KeyCode::A)) {
		pencils->position.x -= 10;
	}
	//right each press down
	if (input()->getKeyDown(KeyCode::D)) {
		pencils->position.x += 10;
	}
	//up constant
	if (input()->getKey(KeyCode::W)) {
		pencils->position.y -= 0.010;
	}
	//down constant
	if (input()->getKey(KeyCode::S)) {
		pencils->position.y += 0.010;
	}

	// go to next scene
	if (input()->getKeyDown(KeyCode::RightBracket)) {
		CoreScene::sceneselect(1);
	}
}
