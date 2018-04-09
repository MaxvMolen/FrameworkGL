/**
* @file scene02.h
*
* @brief The Scene02 header file.
*/

#ifndef SCENE02_H
#define SCENE02_H

#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <string>
#include <vector>

#include <glm/glm.hpp>

#include <FrameworkMvdM/scene.h>
#include <Demo/corescene.h>

/// @brief The Corescene class
class Scene02 : public CoreScene
{
public:
	Scene02();///< @brief Constructor of an Corescene
	virtual ~Scene02();///< @brief Destructor of an Corescene

	/// @brief update this Corescene. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime);

protected:

private:
	BasicEntity* rgba;
	BasicEntity* kingkong;
	BasicEntity* pencils;
};


#endif /* SCENE02_H */
