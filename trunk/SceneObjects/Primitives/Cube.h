#ifndef cube_h
#define cube_h

#include "PrimitiveMesh.h"

class Cube : public PrimitiveMesh
{
private:
	float size;
public:
	Cube(float sideLength) :
		size(sideLength)
	{
		vertices.push_back(Vector3( 1,  1,  1));
		vertices.push_back(Vector3( 1, -1,  1));
		vertices.push_back(Vector3( 1, -1, -1));
		vertices.push_back(Vector3( 1,  1, -1));
		vertices.push_back(Vector3(-1,  1,  1));
		vertices.push_back(Vector3(-1, -1,  1));
		vertices.push_back(Vector3(-1, -1, -1));
		vertices.push_back(Vector3(-1,  1, -1));

		for(unsigned int i = 0; i < vertices.size(); i++)
			vertices.at(i) *= (0.5 * size);

		faces.push_back(PrimitiveFace(6, 1, 2, 3));
		faces.push_back(PrimitiveFace(3, 2, 6, 7));
		faces.push_back(PrimitiveFace(7, 4, 5, 6));
		faces.push_back(PrimitiveFace(4, 0, 1, 5));
		faces.push_back(PrimitiveFace(0, 3, 7, 4));
		faces.push_back(PrimitiveFace(1, 2, 6, 5));
	}
};

#endif
