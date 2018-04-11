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
	// Test Entity
	//##############
	rgba = new BasicEntity();
	rgba->addSprite("assets/rgba.tga");
	rgba->position = glm::vec3(200, 200, 0);
	layers[3]->addChild(rgba);
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

	this->removeChild(rgba);
	delete rgba;

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

	//player->bounderiesv2(rgba->position.x+10, rgba->position.y+10, rgba->position.x - 10, rgba->position.y - 10);
}
