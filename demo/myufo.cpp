/**
* This class describes MyUfo behavior.
*
* Copyright 2017 Max van der Molen <maxharm1811@gmail.com>
*/

#include <demo/myufo.h>

// speed of rotation
int rotationSpeed = 5;
// speed of player
int speed = 300;

MyUfo::MyUfo() : Entity()
{
	this->addSprite("assets/StartUfo1.tga");
}

MyUfo::~MyUfo()
{

}

void MyUfo::update(float deltaTime)
{
	// ###############################################################
	// Rotate player automatic
	// ###############################################################
	this->rotation.x -= rotationSpeed * deltaTime; // 90 deg/sec
	if (this->rotation.x > 6.283185307179586476925286766559) {
		this->rotation.x -= 6.283185307179586476925286766559;
	}
	// ###############################################################
	// Rotate player faster with Q
	// ###############################################################
	if (input()->getKey(KeyCode::Q)) {
		this->rotation.x -= rotationSpeed * deltaTime; // 90 deg/sec
		speed = 600;
		if (this->rotation.x > 6.283185307179586476925286766559) {
			this->rotation.x -= 6.283185307179586476925286766559;
		}
	}
	// Standard speed
	else {
		speed = 300;
	}
	// ###############################################################
	// Update Movement
	// ###############################################################
	movement(deltaTime);
	// ###############################################################
	// Update Bounderies  width,height
	// ###############################################################
	bounderies(SWIDTH,SHEIGHT);
}

void MyUfo::movement(float deltaTime) {
	// ###############################################################
	// Move myentity with arrowkeys
	// ###############################################################
	if (input()->getKey(KeyCode::W)) {
		this->position.y -= speed * deltaTime;
	}
	if (input()->getKey(KeyCode::S)) {
		this->position.y += speed * deltaTime;
	}
	if (input()->getKey(KeyCode::A)) {
		this->position.x -= speed * deltaTime;
	}
	if (input()->getKey(KeyCode::D)) {
		this->position.x += speed * deltaTime;
	}
}

void MyUfo::bounderies(float width, float height) {
	// ###############################################################
	// Check if player exeeds given position and push it back
	// ###############################################################
	if (this->position.x >= width) {
		this->position.x += -10;
	}
	if (this->position.x <= 0) {
		this->position.x += 10;
	}
	if (this->position.y >= height) {
		this->position.y += -10;
	}
	if (this->position.y <= 0) {
		this->position.y += 10;
	}
}
