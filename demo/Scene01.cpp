/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

Scene01::Scene01() : CoreScene()
{
	//##############
	// Background
	//##############
	background = new BasicEntity();
	background->addSprite("assets/StartBackgroundTut.tga");
	background->position = glm::vec3(SWIDTH / 2, SHEIGHT / 2, 0);
	//background->scale = glm::vec3(1, 1, 1);
	layers[1]->addChild(background);
	//##############
	// Player
	//##############
	player = new MyUfo();
	player->position = glm::vec3(600, 200, 0);
	layers[7]->addChild(player);
}

Scene01::~Scene01()
{
	this->removeChild(background);
	delete background;

	this->removeChild(player);
	delete player;
}

void Scene01::update(float deltaTime) {
	//##############
	// Change Scene to Scene02
	//##############
	// go to next scene
	if (input()->getKeyDown(KeyCode::RightBracket)) {
		CoreScene::sceneselect(1);
	}
}
