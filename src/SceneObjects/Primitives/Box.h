#ifndef box_h
#define box_h

#include "../Mesh.h"

class Dimension3
{
private:
public:
	float x, y, z;

	Dimension3(float a, float b, float c) : x(a), y(b), z(c)
	{
	}

	Dimension3 operator*(float scale)
	{
		return Dimension3(x * scale, y * scale, z * scale);
	}
};

class Box : public Mesh
{
	Dimension3 d;
public:
	Box(Dimension3 dim, Position3 centre) :
		Mesh(centre),
		d(dim * 0.5f)
	{
		vertices.push_back(Position3( d.x,  d.y,  d.z));
		vertices.push_back(Position3( d.x, -d.y,  d.z));
		vertices.push_back(Position3(-d.x, -d.y,  d.z));
		vertices.push_back(Position3(-d.x,  d.y,  d.z));
		vertices.push_back(Position3( d.x,  d.y, -d.z));
		vertices.push_back(Position3( d.x, -d.y, -d.z));
		vertices.push_back(Position3(-d.x, -d.y, -d.z));
		vertices.push_back(Position3(-d.x,  d.y, -d.z));

		faces.push_back(Face(0, 1, 2, 3));
		faces.push_back(Face(3, 2, 6, 7));
		faces.push_back(Face(7, 4, 5, 6));
		faces.push_back(Face(4, 0, 1, 5));
		faces.push_back(Face(0, 3, 7, 4));
		faces.push_back(Face(1, 2, 6, 5));
	}
};

#endif
