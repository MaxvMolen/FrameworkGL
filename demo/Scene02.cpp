/**
* @file scene02.cpp
*
* @brief The Scene02 cpp file.
*/

#include <Demo/scene02.h>

Scene02::Scene02() : CoreScene()
{	
	//##############
	// Background
	//##############
	background = new BasicEntity();
	background->addSprite("assets/background.tga");
	background->position = glm::vec3(SWIDTH / 2, SHEIGHT / 2, 0);
	layers[1]->addChild(background);
	//##############
	// Credits
	//##############
	credits = new BasicEntity();
	credits->addSprite("assets/credits.tga");
	credits->position = glm::vec3(SWIDTH / 2, 100, 0);
	layers[6]->addChild(credits);
	//##############
	// Logo
	//##############
	logo = new BasicEntity();
	logo->addSprite("assets/AC-Logo.tga");
	logo->scale = glm::vec3(0.3, 0.3, 0);
	logo->position = glm::vec3(SWIDTH / 2, 1080-100, 0);
	layers[6]->addChild(logo);
}

Scene02::~Scene02()
{
	this->removeChild(background);
	delete background;

	this->removeChild(credits);
	delete credits;

	this->removeChild(logo);
	delete logo;
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
