/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

// the amount of certain objects
int obstacleAmount = 11;
int blackholeAmount = 3;
// radius of the player
float playerRadius = 25;

Scene01::Scene01() : CoreScene()
{
	//##############
	// Background
	//##############
	background = new BasicEntity();
	background->addSprite("assets/background.tga");
	background->position = glm::vec3(SWIDTH / 2, SHEIGHT / 2, 0);
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
		obstacle->position = glm::vec3(75, 400, 0);
		obstacle->position.x += i * 175;
		if (i > 5) {
			obstacle->position = glm::vec3(75, 700, 0);
			obstacle->position.x += (i) * 175;
		}
		layers[5]->addChild(obstacle);
	}
	//##############
	// Black hole
	//##############
	for (int i = 0; i < blackholeAmount; ++i) {
		MyBlackHole* blackhole = new MyBlackHole();
		bhole.push_back(blackhole);
		blackhole->addSprite("assets/pencils.tga");
		blackhole->position = glm::vec3(175, 100, 0);
		blackhole->position.x += i * 175;
		layers[6]->addChild(blackhole);
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
	
	for (int i = 0; i < bhole.size(); ++i) {
		delete bhole[i];
		bhole[i] = NULL;
	}
	bhole.clear();

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
	// Collision
	//##############
	// obstacles
	for (int i = 0; i < myobstacle.size(); ++i) {
		collision(player, playerRadius, myobstacle[i], 125, 1);
	}
	// black hole
	for (int i = 0; i < bhole.size(); ++i) {
		collision(player, playerRadius, bhole[i], 125, 3);
	}
	// finish
	collision(player, playerRadius, finish, 125, 2);
}

void Scene01::collision(Entity* player, float ru, Entity* object, float re, float no) {
	if ((player->position.x - object->position.x)*(player->position.x - object->position.x) + (player->position.y - object->position.y)*(player->position.y - object->position.y) < ru*re) {
		// obstacle
		if (no == 1) {
			// respawn the player at the start
			player->position = glm::vec3(600, 200, 0);
		}
		// finish
		if (no == 2) {
			// go to the next scene and respawn player
			CoreScene::sceneselect(1);
			player->position = glm::vec3(600, 200, 0);
		}
		// lock
		if (no == 3) {
			// lock the ufo in place on collision of object 
			player->position.x = object->position.x;
			player->position.y = object->position.y;
		}
	}
}
