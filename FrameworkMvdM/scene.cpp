/**
* @file scene.cpp
*
* @brief The Scene cpp file.
*/

#include <FrameworkMvdM/scene.h>

Scene::Scene() : Entity()
{
	std::cout << "new scene" << std::endl;
	_camera = new Camera();
	
	_isRunning = true;
}

Scene::~Scene()
{
	delete _camera;
}

void Scene::update(float deltaTime) {
	this->_updateEntity(this, deltaTime); 
}

void Scene::_updateEntity(Entity* entity, float deltaTime) {
	// call the update() of this entity
	entity->update(deltaTime);

	// update() all the children of this entity
	std::vector<Entity*> children = entity->children();
	std::vector<Entity*>::iterator child;
	for (child = children.begin(); child != children.end(); child++) {
		this->_updateEntity(*child, deltaTime);
	}


}

