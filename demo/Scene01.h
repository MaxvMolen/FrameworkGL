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
	/// @brief the background of the game
	BasicEntity* background;
	/// @brief the obstacle the player needs to avoid
	std::vector<BasicEntity*> myobstacle;
	/// @brief the player
	MyUfo* player;
};


#endif /* SCENE01_H */
