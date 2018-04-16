/**
* @file myobstacle.cpp
*
* @brief The MyObstacle cpp file.
*/

#include <demo/myobstacle.h>

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

}
