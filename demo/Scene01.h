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
	/// @brief this function turns myufo red on collision with the given object.
	/// @brief it also will lock the player on the object it collided with.
	/// @brief the player can free itself with the w key.
	/// @param xu the x-position of the ufo
	/// @param yu the y-position of the ufo
	/// @param ru the radius of the ufo
	/// @param xe the x-position of the object
	/// @param ye the y-position of the object
	/// @param re the radius of the object
	/// @param no the number specific to the object
	/// @return void
	void collision(float xu, float yu, float ru, float xe, float ye, float re, float no, float deltaTime);

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
