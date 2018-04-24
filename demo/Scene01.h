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

protected:

private:
	/// @brief sprites for the objects
	Sprite* back;
	Sprite* hole;
	Sprite* obstac;
	Sprite* live;
	Sprite* fin;
	Sprite* gover;
	/// @brief the background of the game
	BasicEntity* background;
	/// @brief a black hole
	std::vector<MyBlackHole*> bhole;
	/// @brief the end goal of the game
	BasicEntity* finish;
	/// @brief the game over message
	BasicEntity* gameover;
	/// @brief the obstacle the player needs to avoid
	std::vector<MyObstacle*> myobstacle;
	/// @brief the lives of the player
	std::vector<BasicEntity*> lives;
	/// @brief the player
	MyUfo* player;
};

#endif /* SCENE01_H */
