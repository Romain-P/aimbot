#ifndef hitbox_h
#define hitbox_h

/*
 * TODO: determine the yaw/pitch/roll of potential hitbox which results in least volume,
 * but still surrounds all vertices.
 *
 * TODO: add 2 child hitboxes to each hitbox containing # vertices > threshold, for log n hit detection.
 */

#include <vector>
#include "../../Utils/Vector3.h"
#include "../Mesh.h"

using std::vector;

class Hitbox
{
private:
	vector<Vector3> vertices;
	Mesh* meshToSurround;
public:
	Hitbox(Mesh* toSurround) : meshToSurround(toSurround)
	{
		calculateSurroundingBox();
	}

	void calculateSurroundingBox()
	{
		float maxX, minX, maxY, minY, maxZ, minZ, x, y, z;
		vector<Vector3>* meshVerts = meshToSurround->vertices;
		for(int i = 0; i < meshVerts->size(); i++)
		{
			x = meshVerts->at(i).x;
			y = meshVerts->at(i).y;
			z = meshVerts->at(i).z;

			if(maxX < x) maxX = x;
			if(maxY < y) maxY = y;
			if(maxZ < z) maxZ = z;

			if(minX > x) minX = x;
			if(minY > y) minY = y;
			if(minZ > z) minZ = z;
		}

		vertices.push_back(maxX, maxY, maxZ);
		vertices.push_back(maxX, minY, maxZ);
		vertices.push_back(maxX, minY, minZ);
		vertices.push_back(maxX, maxY, minZ);
		vertices.push_back(minZ, maxY, maxZ);
		vertices.push_back(minZ, minY, maxZ);
		vertices.push_back(minZ, minY, minZ);
		vertices.push_back(minZ, maxY, minZ);
	}

	vector<Vector3>& getVertices()
	{
		return vertices;
	}
};

#endif
