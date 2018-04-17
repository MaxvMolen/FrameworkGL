/**
* @file scene01.h
*
* @brief The Scene01 header file.
*/

#ifndef SCENE01_H
#define SCENE01_H

#include <Demo/corescene.h>

/// @brief The Corescene class
class Scene01 : public CoreScene
{
public:
	Scene01();///< @brief Constructor of an Corescene
	virtual ~Scene01();///< @brief Destructor of an Corescene

	/// @brief update this Corescene. This function is Pure virtual. User MUST implement this in subclass.
	/// @param deltaTime The time that's passed since the last update.
	/// @return void
	virtual void update(float deltaTime);
	/// @brief this function is used for collision between two objects
	/// @brief it will respawn the player on collision or move to the next scene depending on the no number
	/// @param xu the x-position of the player
	/// @param yu the y-position of the player
	/// @param ru the radius of the player
	/// @param xe the x-position of the object
	/// @param ye the y-position of the object
	/// @param re the radius of the object
	/// @param no the given number specifies if it will respawn the player or move to the next scene
	/// @return void
	void collision(float xu, float yu, float ru, float xe, float ye, float re, float no);

protected:

private:
	/// @brief the background of the game
	BasicEntity* background;
	/// @brief the end goal of the game
	BasicEntity* finish;
	/// @brief the obstacle the player needs to avoid
	std::vector<MyObstacle*> myobstacle;
	/// @brief the player
	MyUfo* player;
};

#endif /* SCENE01_H */
