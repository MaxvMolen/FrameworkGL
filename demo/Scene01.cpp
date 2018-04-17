/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

// the amount of certain objects
int obstacleAmount = 11;

// radius of the player
float playerRadius = 25;

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
	finish->position = glm::vec3(SWIDTH / 2, 1080-75, 0);
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
	//##############
	// Collision for obstacles
	//##############
	for (int i = 0; i < myobstacle.size(); ++i) {
		collision(player->position.x, player->position.y, playerRadius, myobstacle[i]->position.x, myobstacle[i]->position.y, 125, 1, deltaTime);
	}
}

void Scene01::collision(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime) {
	if ((xu - xe)*(xu - xe) + (yu - ye)*(yu - ye) < ru*re) {

		// free the object
		if (input()->getKey('Q')) {
		
		}
		// lock the ufo in place on collision of object 
		else {
			player->position.x = xe;
			player->position.y = ye;
		}
	}
}
