/*
 * SceneObject.cpp
 *
 *  Created on: Jun 16, 2009
 *      Author: Corey
 */

#include "SceneObject.h"

Vector2 SceneObject::getMomentum()
{
	//your momentum
	Vector2 yourMom = Vector2(this->velocity.getX() * this->mass, this->velocity.getY());
	return yourMom;
}

float SceneObject::getMass()
{
	return mass;
}

Mesh SceneObject::getObjectMesh()
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
