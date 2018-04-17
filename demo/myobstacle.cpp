/**
* @file myobstacle.cpp
*
* @brief The MyObstacle cpp file.
*/

#include <demo/myobstacle.h>

// speed of rotation
int rotationS = 2;

MyObstacle::MyObstacle() : Entity()
{
	// ###############################################################
	// Set texture
	// ###############################################################
	this->addSprite("assets/rgba.tga");
}

MyObstacle::~MyObstacle()
{

}

void MyObstacle::update(float deltaTime)
{
	// ###############################################################
	// Rotate player automatic
	// ###############################################################
	this->rotation.x -= rotationS * deltaTime; // 90 deg/sec
	if (this->rotation.x > TWO_PI) {
		this->rotation.x -= TWO_PI;
	}
}
