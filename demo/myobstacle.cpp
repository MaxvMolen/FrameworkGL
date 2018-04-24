/**
* @file myobstacle.cpp
*
* @brief The MyObstacle cpp file.
*/

#include <demo/myobstacle.h>

// speed of rotation
int rotationS = 2;

int speedObj = 20;

float distance = 0;

MyObstacle::MyObstacle() : Entity()
{
	// ###############################################################
	// Set texture
	// ###############################################################
	//this->addSprite("assets/portal.tga");
}

MyObstacle::~MyObstacle()
{

}

void MyObstacle::update(float deltaTime)
{
	// ###############################################################
	// Rotate object automatic
	// ###############################################################
	this->rotation.x -= rotationS * deltaTime; // 90 deg/sec
	if (this->rotation.x > TWO_PI) {
		this->rotation.x -= TWO_PI;
	}
	// ###############################################################
	// Move forward and backwards
	// ###############################################################
	if (distance <= 500) {
		this->position.x += speedObj * deltaTime;
		distance += speedObj * deltaTime;
	}
	else if (distance >= 500 && distance <= 1000) {
		this->position.x -= speedObj * deltaTime;
		distance += speedObj * deltaTime;
	}
	else {
		distance = 0;
	}
}
