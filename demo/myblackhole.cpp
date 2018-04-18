/**
* @file myobstacle.cpp
*
* @brief The MyObstacle cpp file.
*/

#include <demo/myblackhole.h>

// speed of rotation
int rotationBHole = 2;

MyBlackHole::MyBlackHole() : Entity()
{
	// ###############################################################
	// Set texture
	// ###############################################################
	this->addSprite("assets/blackhole.tga");
}

MyBlackHole::~MyBlackHole()
{

}

void MyBlackHole::update(float deltaTime)
{
	// ###############################################################
	// Rotate object automatic
	// ###############################################################
	this->rotation.x -= rotationBHole * deltaTime; // 90 deg/sec
	if (this->rotation.x > TWO_PI) {
		this->rotation.x -= TWO_PI;
	}
}
