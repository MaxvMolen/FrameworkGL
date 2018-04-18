/**
* @file myblackhole.h
*
* @brief The MyBlackHole header file.
*/

#ifndef MYBLACKHOLE_H
#define MYBLACKHOLE_H

#include <FrameworkMvdM/entity.h>

/// @brief The MyBlackHole class
class MyBlackHole : public Entity
{
public:
	/// @brief Constructor
	MyBlackHole();
	/// @brief Destructor
	virtual ~MyBlackHole();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYBLACKHOLE_H */
