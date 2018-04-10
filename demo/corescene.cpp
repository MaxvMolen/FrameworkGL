/**
* @file corescene.cpp
*
* @brief The Corescene cpp file.
*/

#include <Demo/corescene.h>

// The current scene
int CoreScene::activescene;

CoreScene::CoreScene() : Scene()
{

}

CoreScene::~CoreScene()
{
	
}

void CoreScene::update(float deltaTime) {

}

void CoreScene::quit() {

}

void CoreScene::sceneselect(int ds) {
	// ###############################################################
	// Desired scene
	// ###############################################################
	activescene = ds;

}

