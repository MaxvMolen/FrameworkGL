/**
* @file corscene.h
*
* @brief The Corescene header file.
*/

#ifndef CORESCENE_H
#define CORESCENE_H

#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <string>
#include <vector>

#include <glm/glm.hpp>

#include <FrameworkMvdM/scene.h>
#include <FrameworkMvdM/entity.h>
#include <Demo/basicentity.h>

/// @brief The Corescene class
class CoreScene : public Scene
{
public:
	CoreScene();///< @brief Constructor of an Corescene
	virtual ~CoreScene();///< @brief Destructor of an Corescene

	/// @brief update this Corescene. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime);
	/// @brief keeps track of the current active scene
	static int activescene;
	/// @brief will bring you back to the main menu of the game
	/// @return void
	virtual void sceneselect(int ds);
protected:
	/// @brief the top layer
	unsigned int top_layer;
	/// @brief list of layers
	std::vector<BasicEntity*> layers;
private:

};


#endif /* CORESCENE_H */
