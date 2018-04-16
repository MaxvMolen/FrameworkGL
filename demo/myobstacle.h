/**
* @file myobstacle.h
*
* @brief The MyObstacle header file.
*/

#ifndef MYOBSTACLE_H
#define MYOBSTACLE_H

#include <FrameworkMvdM/entity.h>

/// @brief The MyObstacle class
class MyObstacle : public Entity
{
public:
	/// @brief Constructor
	MyObstacle();
	/// @brief Destructor
	virtual ~MyObstacle();
	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* MYOBSTACLE_H */
