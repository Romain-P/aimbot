#ifndef cube_h
#define cube_h

#include "../Mesh.h"

class Cube : public Mesh
{
private:
	float size;
public:
	Cube(float sideLength, Position3 centre) :
		Mesh(centre),
		size(sideLength)
	{
		vertices.push_back(Position3( 1,  1,  1));
		vertices.push_back(Position3( 1, -1,  1));
		vertices.push_back(Position3(-1, -1,  1));
		vertices.push_back(Position3(-1,  1,  1));
		vertices.push_back(Position3( 1,  1, -1));
		vertices.push_back(Position3( 1, -1, -1));
		vertices.push_back(Position3(-1, -1, -1));
		vertices.push_back(Position3(-1,  1, -1));

		for(unsigned int i = 0; i < vertices.size(); i++)
			vertices.at(i) *= (0.5 * size);

		faces.push_back(Face(0, 1, 2, 3));
		faces.push_back(Face(3, 2, 6, 7));
		faces.push_back(Face(7, 4, 5, 6));
		faces.push_back(Face(4, 0, 1, 5));
		faces.push_back(Face(0, 3, 7, 4));
		faces.push_back(Face(1, 2, 6, 5));
	}
};

#endif
