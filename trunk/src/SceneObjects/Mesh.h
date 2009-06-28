#ifndef mesh_h
#define mesh_h

#include <vector>
#include <string>
#include <fstream>
#include "../Utils/Structures/Vector3.h"

using std::vector;
using std::string;
using std::fstream;

class Face
{
public:
	int indices[4];
	Face()
	{
		indices[0] = 0;
		indices[1] = 0;
		indices[2] = 0;
		indices[3] = 0;
	}

	Face(int a, int b, int c, int d)
	{
		indices[0] = a;
		indices[1] = b;
		indices[2] = c;
		indices[3] = d;
	}
};

class Mesh
{
private:
	vector<Vector3> vertices;
	vector<Face> faces;

	void read(const string& filename)
	{
		fstream in;
		int numVertices, numFaces;
		in.open(filename.c_str(), std::ios::in);

		in >> numVertices;
		float x, y, z;
		for(int i = 0; i < numVertices; i++)
		{
			in >> x >> y >> z;
			vertices.push_back(Vector3(x, y, z));
		}

		in >> numFaces;
		int a, b, c, d;
		for(int i = 0; i < numFaces; i++)
		{
			in >> a >> b >> c >> d;
			faces.push_back(Face(a, b, c, d));
		}
	}
public:
	Mesh()
	{
	}

	Mesh(const string& filename)
	{
		read(filename);
	}

	const vector<Vector3>& getVertices()
	{
		return vertices;
	}

	const vector<Face>& getFaces()
	{
		return faces;
	}
};

#endif
