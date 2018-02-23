#ifndef ENTITY_H
#define ENTITY_H

#include <iostream>
#include <cstdio>
#include <GL/glew.h>
#include <string>
#include <vector>

#include <glm/glm.hpp>
//#include <glm/gtc/matrix_transform.hpp>
//#include <glm/gtx/euler_angles.hpp>

#include <common/sprite.h>
class Entity
{
public:
	virtual ~Entity();
	virtual void update(float deltaTime) = 0;

private:

};

#endif /* ENTITY_H */
