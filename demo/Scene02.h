/**
* @file scene02.h
*
* @brief The Scene02 header file.
*/

#ifndef SCENE02_H
#define SCENE02_H

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
	/// @brief sprites for the objects
	Sprite* back;
	Sprite* cred;
	Sprite* log;
	/// @brief the background of the game
	BasicEntity* background;
	/// @brief the credits
	BasicEntity* credits;
	/// @brief the alfa logo
	BasicEntity* logo;
};


#endif /* SCENE02_H */
