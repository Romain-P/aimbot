#ifndef mesh_h
#define mesh_h

#include <vector>
#include <string>
#include <fstream>
#include <exception>
#include "../../Utils/Structures/Position3.h"

using std::vector;
using std::string;
using std::fstream;
using std::exception;
using std::cout;
using std::endl;

class Face
{
public:
	int order;
	int indices[4];
	Face()
	{
		order = 4;
		indices[0] = 0;
		indices[1] = 0;
		indices[2] = 0;
		indices[3] = 0;
	}

	Face(int a, int b, int c, int d)
	{
		order = 4;
		indices[0] = a;
		indices[1] = b;
		indices[2] = c;
		indices[3] = d;
	}

	Face(int a, int b, int c)
	{
		order = 3;
		indices[0] = a;
		indices[1] = b;
		indices[2] = c;
	}
};

class Mesh
{
protected:
	Position3 centre;
	vector<Position3> vertices;
	vector<Face> faces;

public:
	Mesh()
	{
		centre = Position3(0, 0, 0);
	}

	Mesh(Position3 centre)
	{
		this->centre = centre;
	}
	const vector<Position3>& getVertices()
	{
		return vertices;
	}

	const vector<Face>& getFaces()
	{
		return faces;
	}

	const Position3& getCentre()
	{
		return centre;
	}

	void setCentre(const Position3& centre)
	{
		this->centre = centre;
	}
};

#endif
