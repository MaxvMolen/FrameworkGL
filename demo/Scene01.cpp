/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

// the amount of certain objects
int obstacleAmount = 11;

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
	//##############
	// Obstacle
	//##############
	for (int i = 0; i < obstacleAmount; ++i) {
		MyObstacle* obstacle = new MyObstacle();
		myobstacle.push_back(obstacle);
		obstacle->position = glm::vec3(75, 100, 0);
		obstacle->position.x += i * 175;
		layers[5]->addChild(obstacle);
	}
	//##############
	// Finish
	//##############
	finish = new BasicEntity();
	finish->addSprite("assets/pencils.tga");
	finish->position = glm::vec3(SWIDTH / 2, SHEIGHT / 2, 0);
	layers[6]->addChild(finish);
}

Scene01::~Scene01()
{
	this->removeChild(background);
	delete background;

	this->removeChild(finish);
	delete finish;

	this->removeChild(player);
	delete player;
	
	for (int i = 0; i < myobstacle.size(); ++i) {
		delete myobstacle[i];
		myobstacle[i] = NULL;
	}
	myobstacle.clear();
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
