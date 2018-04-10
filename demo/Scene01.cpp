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
	player = new BasicEntity();
	player->addSprite("assets/StartUfo1.tga");
	player->position = glm::vec3(600, 200, 0);
	layers[7]->addChild(player);
}

Scene01::~Scene01()
{
	delete background;
	delete rgba;
	delete player;
}

void Scene01::update(float deltaTime) {
	//##############
	//Movement
	//##############
	//left
	if (input()->getKey(KeyCode::A)) {
		player->position.x -= MovementSpeed * deltaTime;
	}
	//right
	if (input()->getKey(KeyCode::D)) {
		player->position.x += MovementSpeed * deltaTime;
	}
	//up
	if (input()->getKey(KeyCode::W)) {
		player->position.y -= MovementSpeed * deltaTime;
	}
	//down
	if (input()->getKey(KeyCode::S)) {
		player->position.y += MovementSpeed * deltaTime;
	}
	//##############
	//Change Scene
	//##############
	// go to next scene
	if (input()->getKeyDown(KeyCode::RightBracket)) {
		CoreScene::sceneselect(1);
	}
}
