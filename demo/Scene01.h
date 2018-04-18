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
	/// @param Entity* player the player entity
	/// @param ru the radius of the player
	/// @param Entity* object the object entity
	/// @param re the radius of the object
	/// @param no the given number specifies if it will respawn the player or move to the next scene
	/// @return void
	void collision(Entity* player, float ru, Entity* object, float re, float no);

protected:

private:
	/// @brief the background of the game
	BasicEntity* background;
	/// @brief a black hole
	std::vector<BasicEntity*> bhole;
	/// @brief the end goal of the game
	BasicEntity* finish;
	/// @brief the obstacle the player needs to avoid
	std::vector<MyObstacle*> myobstacle;
	/// @brief the player
	MyUfo* player;
};

#endif /* SCENE01_H */
