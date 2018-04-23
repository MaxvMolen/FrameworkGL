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
	// set the amount of layers there are
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

void CoreScene::collision(Entity* object1, float ru, Entity* object2, float re, float no) {
	if ((object1->position.x - object2->position.x)*(object1->position.x - object2->position.x) + (object1->position.y - object2->position.y)*(object1->position.y - object2->position.y) < ru*re) {
		// obstacle
		if (no == 1) {
			// teleport player to random x and y position
			object1->position.x = rand() % 1920 + 1;
			object1->position.y = rand() % 1080 + 1;

		}
		// finish
		if (no == 2) {
			// go to the next scene and respawn player
			CoreScene::sceneselect(1);
			object1->position = glm::vec3(600, 200, 0);
		}
		// lock
		if (no == 3) {
			// lock the ufo in place on collision of object 
			object1->position.x = object2->position.x;
			object1->position.y = object2->position.y;
		}
	}
}


