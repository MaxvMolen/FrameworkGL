/**
* @file core.h
*
* @brief The Core header file.
*/

#ifndef CORE_H
#define CORE_H

// Include GLEW
#include <GL/glew.h>

// Include GLFW
#include <glfw3.h>

#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <string>

#include <glm/glm.hpp>

#include <FrameworkMvdM/renderer.h>
#include <FrameworkMvdM/entity.h>
#include <FrameworkMvdM/scene.h>
#include <FrameworkMvdM/input.h>
/// @brief The Core class
class Core
{
public:
	Core();///< @brief Constructor of an Core
	virtual ~Core();///< @brief Destructor of an Core

	/// @brief update this Core. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	void run(Scene* scene);
	/// @brief update this Core. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	void cleanup();
	/// @brief update this Core. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	float deltaTime() { return (float)_deltaTime; };
	/// @brief update this Core. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	void showFrameRate(float numesecs);

private:
	Renderer _renderer; ///< @brief The Renderer

	double _calculateDeltaTime(); ///< @brief updates deltaTime internally
	double _deltaTime; ///< @brief deltaTime
};


#endif /* CORE_H */
