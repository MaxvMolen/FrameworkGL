/**
* @file scene.h
*
* @brief The Scene header file.
*/

#ifndef SCENE_H
#define SCENE_H

#include <FrameworkMvdM/entity.h>
#include <FrameworkMvdM/camera.h>

/// @brief The Scene class
class Scene : public Entity
{
public:
	Scene(); ///< @brief Constructor of an Scene
	virtual ~Scene(); ///< @brief Destructor of an Scene

	/// @brief if this scene is running or not
	/// @return bool _isRunning
	//bool isRunning() { return _isRunning; };

	/// @brief get a pointer to the Camera
	/// @return Camera* a pointer to the Camera
	//Camera* camera() { return _camera; };

	/// @brief update this Scene. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime);

private:
	// need to make camera class
	//Camera* _camera; ///< @brief the Camera instance

	bool _isRunning; ///< @brief if the scene is running or not
};


#endif /* SCENE_H */
