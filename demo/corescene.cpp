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
	top_layer = 8;
	// ###############################################################
	// Create layers
	// ###############################################################
	for (unsigned int i = 0; i <= top_layer; i++) {
		BasicEntity* layer = new BasicEntity();
		layers.push_back(layer);
		this->addChild(layer);
	}
}

CoreScene::~CoreScene()
{
	// deconstruct and delete the Tree
	int ls = layers.size();
	for (int i = 0; i<ls; i++) {
		this->removeChild(layers[i]);
		delete layers[i];
		layers[i] = NULL;
	}
	layers.clear();
}

void CoreScene::update(float deltaTime) {

}

void CoreScene::sceneselect(int ds) {
	// ###############################################################
	// Desired scene
	// ###############################################################
	activescene = ds;

}

