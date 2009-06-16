/*
 * SceneObject.h
 *
 *  Created on: Jun 16, 2009
 *      Author: Corey
 */

#ifndef SCENEOBJECT_H_
#define SCENEOBJECT_H_

#include <math.h>
#include <iostream>
#include <vector>
#include <fstream>
#include "../Graphics/GraphicIncludes.h"
#include "../Utils/Vector2.h"
#include "Mesh.h"

using namespace std;

class SceneObject
{

protected:
	Mesh objectMesh;
	float mass;
	Vector2 velocity;
	float density;


public:


	Vector2 SceneObject::getMomentum();
	float SceneObject::getMass();
	float SceneObject::getDensity();
	Mesh SceneObject::getObjectMesh();

	void SceneObject::setMass(float m);
	void SceneObject::setDensity(float d);



};




#endif /* SCENEOBJECT_H_ */
