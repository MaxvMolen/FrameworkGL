/**
* @file scene02.cpp
*
* @brief The Scene02 cpp file.
*/

#include <Demo/scene02.h>

Scene02::Scene02() : CoreScene()
{	
	//##############
	// Rgba
	//##############
	rgba = new BasicEntity();
	rgba->addSprite("assets/rgba.tga");
	rgba->position = glm::vec3(200, 200, 0);
	layers[1]->addChild(rgba);
	//##############
	// Kingkong
	//##############
	kingkong = new BasicEntity();
	kingkong->addSprite("assets/rgba.tga");
	kingkong->position = glm::vec3(400, 200, 0);
	layers[1]->addChild(kingkong);
	//##############
	// Pencils
	//##############
	pencils = new BasicEntity();
	pencils->addSprite("assets/rgba.tga");
	pencils->position = glm::vec3(600, 200, 0);
	layers[1]->addChild(pencils);
}

Scene02::~Scene02()
{
	this->removeChild(rgba);
	delete rgba;

	this->removeChild(kingkong);
	delete kingkong;

	this->removeChild(pencils);
	delete pencils;
}

void Scene02::update(float deltaTime) {
	//##############
	//Change Scene to Scene01
	//##############
	// go to previous scene
	if (input()->getKeyDown(KeyCode::LeftBracket)) {
		CoreScene::sceneselect(0);
	}
}
