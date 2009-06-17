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


	Vector2 getMomentum();
	float getMass();
	float getDensity();
	Mesh getObjectMesh();

	void setMass(float m);
	void setDensity(float d);



};




#endif /* SCENEOBJECT_H_ */
