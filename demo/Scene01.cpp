/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

int MovementSpeed = 100;

Scene01::Scene01() : CoreScene()
{
	//##############
	//Background
	//##############
	background = new BasicEntity();
	background->addSprite("assets/StartBackgroundTut.tga");
	background->position = glm::vec3(SWIDTH / 2, SHEIGHT / 2, 0);
	//kingkong->scale = glm::vec3(1, 1, 1);
	layers[1]->addChild(background);
	//##############
	//Test Entity
	//##############
	rgba = new BasicEntity();
	rgba->addSprite("assets/rgba.tga");
	rgba->position = glm::vec3(200, 200, 0);
	layers[3]->addChild(rgba);
	//##############
	//Player
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
	//Call update of player (not done automatically)
	//##############
	player->update(deltaTime);
	//##############
	//Change Scene
	//##############
	// go to next scene
	if (input()->getKeyDown(KeyCode::RightBracket)) {
		CoreScene::sceneselect(1);
	}
}
