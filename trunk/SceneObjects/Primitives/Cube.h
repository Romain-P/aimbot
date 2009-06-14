#ifndef cube_h
#define cube_h

#include "PrimitiveMesh.h"

class Cube : private PrimitiveMesh
{
private:
	float size;
public:
	Cube(float sideLength) :
		size(sideLength)
	{
		vertices.push_back(new Vector( 1,  1,  1));
		vertices.push_back(new Vector( 1, -1,  1));
		vertices.push_back(new Vector( 1, -1, -1));
		vertices.push_back(new Vector( 1,  1, -1));
		vertices.push_back(new Vector(-1,  1,  1));
		vertices.push_back(new Vector(-1, -1,  1));
		vertices.push_back(new Vector(-1, -1, -1));
		vertices.push_back(new Vector(-1,  1, -1));

		for(int i = 0; i < vertices.length(); i++)
			*vertices.at(i) *= size;

	}
};

#endif
