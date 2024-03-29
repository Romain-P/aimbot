/*
 * SceneObject.cpp
 *
 *  Created on: Jun 16, 2009
 *      Author: Corey
 */

#include "SceneObject.h"
//Added just to debug
#include "../Physics/CollisionDetector.h"

Vector2 SceneObject::getMomentum()
{
	//your momentum
	return Vector2(velocity.x * mass, velocity.y);
}

float SceneObject::getMass()
{
	return mass;
}

const Mesh& SceneObject::getObjectMesh()
{
	return objectMesh;
}

float SceneObject::getDensity()
{
	return density;
}

void SceneObject::setMass(float m)
{
	this->mass = m;
}

void SceneObject::setDensity(float d)
{
	this->density = d;
}
