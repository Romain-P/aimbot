#ifndef hitbox_h
#define hitbox_h

/*
 * TODO: determine the yaw/pitch/roll of potential hitbox which results in least volume,
 * but still surrounds all vertices.
 *
 * TODO: add 2 child hitboxes to each hitbox containing # vertices > threshold, for log n hit detection.
 */

#include <vector>
#include "../Utils/Structures/Position3.h"
#include "../Utils/Math/LinearRegression.h"
#include "Mesh.h"

using std::vector;

class Hitbox
{
private:
	vector<Position3> vertices;
	Mesh* meshToSurround;
public:
	Hitbox(Mesh* toSurround) : meshToSurround(toSurround)
	{
		calculateSurroundingBox();
	}

	void calculateSurroundingBox()
	{
		float maxX, minX, maxY, minY, maxZ, minZ, x, y, z;
		const vector<Position3>& meshVerts = meshToSurround->getVertices();
		vector<Position3>::const_iterator it;
		for(it = meshVerts.begin(); it != meshVerts.end(); ++it)
		{
			x = it->x;
			y = it->y;
			z = it->z;

			if(maxX < x) maxX = x;
			if(maxY < y) maxY = y;
			if(maxZ < z) maxZ = z;

			if(minX > x) minX = x;
			if(minY > y) minY = y;
			if(minZ > z) minZ = z;
		}

		vertices.push_back(Position3(maxX, maxY, maxZ));
		vertices.push_back(Position3(maxX, minY, maxZ));
		vertices.push_back(Position3(maxX, minY, minZ));
		vertices.push_back(Position3(maxX, maxY, minZ));
		vertices.push_back(Position3(minZ, maxY, maxZ));
		vertices.push_back(Position3(minZ, minY, maxZ));
		vertices.push_back(Position3(minZ, minY, minZ));
		vertices.push_back(Position3(minZ, maxY, minZ));
	}

	vector<Position3>& getVertices()
	{
		return vertices;
	}
};

#endif
