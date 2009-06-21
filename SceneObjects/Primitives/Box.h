#ifndef box_h
#define box_h

#include "PrimitiveMesh.h"

class Box : public PrimitiveMesh
{
	float x;
	float y;
	float z;
public:
	Box(float xLength, float yLength, float zLength) :
		x(0.5 * xLength),
		y(0.5 * yLength),
		z(0.5 * zLength)
	{
		vertices.push_back(Vector3( x,  y,  z));
		vertices.push_back(Vector3( x, -y,  z));
		vertices.push_back(Vector3(-x, -y,  z));
		vertices.push_back(Vector3(-x,  y,  z));
		vertices.push_back(Vector3( x, -y, -z));
		vertices.push_back(Vector3( x, -y, -z));
		vertices.push_back(Vector3(-x,  y, -z));
		vertices.push_back(Vector3(-x,  y, -z));

		faces.push_back(PrimitiveFace(6, 1, 2, 3));
		faces.push_back(PrimitiveFace(3, 2, 6, 7));
		faces.push_back(PrimitiveFace(7, 4, 5, 6));
		faces.push_back(PrimitiveFace(4, 0, 1, 5));
		faces.push_back(PrimitiveFace(0, 3, 7, 4));
		faces.push_back(PrimitiveFace(1, 2, 6, 5));
	}
};

#endif
