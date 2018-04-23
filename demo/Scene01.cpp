/**
* @file scene01.cpp
*
* @brief The Scene01 cpp file.
*/

#include <Demo/scene01.h>

// the amount of certain objects
int obstacleAmount = 11;
int blackholeAmount = 3;

// lives of the player
int liveAmount = 3;
int livesPlayer = 3;

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
	layers[0]->addChild(background);
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
		obstacle->position = glm::vec3(75, rand() % 1080 + 1, 0);
		obstacle->position.x += i * 175;
		obstacle->scale = glm::vec3(0.5, 0.5, 0);
		if (i > 5) {
			obstacle->position = glm::vec3(75, rand() % 1080 + 1, 0);
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
		blackhole->position = glm::vec3(760, 975, 0);
		blackhole->scale = glm::vec3(0.7, 0.7, 0);
		blackhole->position.x += i * 200;
		if (i == 1) {
			blackhole->position.y -= 100;
		}
		layers[5]->addChild(blackhole);
	}
	//##############
	// The lives of the player
	//##############
	for (int i = 0; i < liveAmount; ++i) {
		BasicEntity* livesPlayer = new BasicEntity();
		lives.push_back(livesPlayer);
		lives[i]->addSprite("assets/lives.tga");
		livesPlayer->position = glm::vec3(175, 200, 0);
		livesPlayer->scale = glm::vec3(0.5, 0.5, 0);
		livesPlayer->position.y += i * 30;
		layers[7]->addChild(livesPlayer);
	}
	//##############
	// Finish
	//##############
	finish = new BasicEntity();
	finish->addSprite("assets/finish.tga");
	finish->position = glm::vec3(SWIDTH / 2, 1080-75, 0);
	finish->scale = glm::vec3(0.5, 0.5, 0);
	layers[6]->addChild(finish);
	//##############
	// Game Over
	//##############
	gameover = new BasicEntity();
	gameover->addSprite("assets/gameover.tga");
	gameover->position = glm::vec3(SWIDTH / 2, SHEIGHT / 2, 0);
}

Scene01::~Scene01()
{
	this->removeChild(background);
	delete background;

	this->removeChild(finish);
	delete finish;

	this->removeChild(gameover);
	delete gameover;

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

	for (int i = 0; i < lives.size(); ++i) {
		delete lives[i];
		lives[i] = NULL;
	}
	lives.clear();
}

void Scene01::update(float deltaTime) {
	//##############
	// Change Scene to Scene02
	//##############
	// go to next scene
	if (input()->getKeyDown(KeyCode::RightBracket)) {
		livesPlayer = 3;
		layers[7]->addChild(player);
		layers[7]->removeChild(gameover);
		layers[7]->addChild(lives[0]);
		layers[7]->addChild(lives[1]);
		layers[7]->addChild(lives[2]);
		CoreScene::sceneselect(1);
	}
	//##############
	// Lives follow player
	//##############
	for (int i = 0; i < lives.size(); ++i) {
		lives[i]->position.x = player->position.x + 50;
		lives[i]->position.y = player->position.y - 30 + i * 30;
	}
	//##############
	// Collision
	//##############
	// obstacles
	for (int i = 0; i < myobstacle.size(); ++i) {
		CoreScene::collision(player, playerRadius, myobstacle[i], 125, 1);
	}
	// black hole
	for (int i = 0; i < bhole.size(); ++i) {
		CoreScene::collision(player, playerRadius, bhole[i], 150, 3);
	}
	// finish
	CoreScene::collision(player, playerRadius, finish, 125, 2);
	//##############
	// Lives
	//##############
	// reduce the amount of lives
	if (input()->getKeyDown(KeyCode::R)) {
		livesPlayer--;
	}
	// game over
	if (livesPlayer == -1) {
		layers[7]->removeChild(player);
		layers[7]->addChild(gameover);
	}
	if (livesPlayer == 0) {
		layers[7]->removeChild(lives[0]);
	}
	if (livesPlayer == 1) {
		layers[7]->removeChild(lives[1]);
	}
	if (livesPlayer == 2) {
		layers[7]->removeChild(lives[2]);
	}
}
