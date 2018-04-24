/**
* @file scene02.cpp
*
* @brief The Scene02 cpp file.
*/

#include <Demo/scene02.h>

Scene02::Scene02() : CoreScene()
{	
	//##############
	// sprites
	//##############
	back = new Sprite("assets/background.tga");
	cred = new Sprite("assets/credits.tga");
	log = new Sprite("assets/AC-Logo.tga");
	//##############
	// Background
	//##############
	background = new BasicEntity();
	background->addSprite(back);
	background->position = glm::vec3(SWIDTH / 2, SHEIGHT / 2, 0);
	layers[0]->addChild(background);
	//##############
	// Credits
	//##############
	credits = new BasicEntity();
	credits->addSprite(cred);
	credits->position = glm::vec3(SWIDTH / 2, 100, 0);
	layers[6]->addChild(credits);
	//##############
	// Logo
	//##############
	logo = new BasicEntity();
	logo->addSprite(log);
	logo->scale = glm::vec3(0.3, 0.3, 0);
	logo->position = glm::vec3(SWIDTH / 2, 1080-100, 0);
	layers[6]->addChild(logo);
}

Scene02::~Scene02()
{
	// clean up sprites
	delete back;
	delete cred;
	delete log;

	// clean up entity's
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
