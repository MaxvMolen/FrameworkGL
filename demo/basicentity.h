#ifndef BASICENTITY_H
#define BASICENTITY_H

#include <FrameworkMvdM/entity.h>

/// @brief The BasicEntity class is the Entity implementation.
class BasicEntity : public Entity
{
public:
	/// @brief Constructor
	BasicEntity();
	/// @brief Destructor
	virtual ~BasicEntity();

	/// @brief update is automatically called every frame
	/// @param deltaTime the elapsed time in seconds
	/// @return void
	virtual void update(float deltaTime);

private:
	/* add your private declarations */
};

#endif /* BASICENTITY_H */
