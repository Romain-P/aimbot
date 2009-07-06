#ifndef hitbox_h
#define hitbox_h

/*
 * TODO: determine the yaw/pitch/roll of potential hitbox which results in least volume,
 * but still surrounds all vertices.
 *
 * TODO: add 2 child hitboxes to each hitbox containing # vertices > threshold, for log n hit detection.
 */

#include <vector>
#include "Mesh.h"
#include "../../Utils/Structures/Position3.h"
#include "../../Utils/Math/LinearRegression.h"

using std::vector;


class Hitbox
{
private:

	class HitboxFace
	{
	public:
		friend class Hitbox;
		Position3 positions[4];
		HitboxFace(int w, int x, int y, int z)
		{
			/*
			positions[0] = vertices.at(w);
			positions[1] = vertices.at(x);
			positions[2] = vertices.at(y);
			positions[3] = vertices.at(z);
			*/
		}

		void operator=(const HitboxFace& other)
		{
			for(int i = 0; i < 4; i++)
				positions[i] = other.positions[i];
		}
	};

	class HitboxVertex
	{
	public:
		friend class Hitbox;
		vector<HitboxFace> connected;
		Position3 vertex;

		HitboxVertex(int a, int b, int c, Position3 vert) :
			vertex(vert)
		{
			/*
			connected.push_back(faces.at(a));
			connected.push_back(faces.at(b));
			connected.push_back(faces.at(c));
			*/
		}

		vector<HitboxFace>& getFaces()
		{
			return connected;
		}
	};


	vector<HitboxVertex> vertices;
	vector<HitboxFace> faces;
	vector<Position3> centroids;

	Mesh* meshToSurround;

	void calculateCentroids()
	{
		Position3 point;
		for(int i = 0; i < 6; i++)
		{
			for(int j = 0; j < 4; j++)
				point += faces.at(i).positions[j];
			point *= 0.25f;
			centroids.push_back(point);
		}
	}

	Vector3 getNormal(int face)
	{
		Vector3 normal;

		for(int i = 0; i < 4; i++) {
			Position3 p = faces.at(face).positions[i];
			Position3 q = faces.at(face).positions[(i+1)%4];

			normal.x += (p.y - q.y) * (p.z + q.z);
			normal.y += (p.z - q.z) * (p.x + q.x);
			normal.z += (p.x - q.x) * (p.y + q.y);
		}
		normal.normalize();
		return normal;
	}

public:
	friend class HitboxVertex;
	friend class HitboxFace;

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

		faces.push_back(HitboxFace(0, 1, 2, 3));
		faces.push_back(HitboxFace(3, 2, 6, 7));
		faces.push_back(HitboxFace(7, 4, 5, 6));
		faces.push_back(HitboxFace(4, 0, 1, 5));
		faces.push_back(HitboxFace(0, 3, 7, 4));
		faces.push_back(HitboxFace(1, 2, 6, 5));

		/*
		vertices.push_back(HitboxVertex(this, Position3(maxX, maxY, maxZ)));
		vertices.push_back(HitboxVertex(this, Position3(maxX, minY, maxZ)));
		vertices.push_back(HitboxVertex(this, Position3(maxX, minY, minZ)));
		vertices.push_back(HitboxVertex(this, Position3(maxX, maxY, minZ)));
		vertices.push_back(HitboxVertex(this, Position3(minZ, maxY, maxZ)));
		vertices.push_back(HitboxVertex(this, Position3(minZ, minY, maxZ)));
		vertices.push_back(HitboxVertex(this, Position3(minZ, minY, minZ)));
		vertices.push_back(HitboxVertex(this, Position3(minZ, maxY, minZ)));
		*/
	}

	vector<HitboxVertex>& getVertices()
	{
		return vertices;
	}
};

#endif
