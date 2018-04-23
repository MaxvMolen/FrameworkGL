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

void CoreScene::collision(Entity* player, float ru, Entity* object, float re, float no) {
	if ((player->position.x - object->position.x)*(player->position.x - object->position.x) + (player->position.y - object->position.y)*(player->position.y - object->position.y) < ru*re) {
		// obstacle
		if (no == 1) {
			// teleport player to random x and y position
			player->position.x = rand() % 1920 + 1;
			player->position.y = rand() % 1080 + 1;

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


