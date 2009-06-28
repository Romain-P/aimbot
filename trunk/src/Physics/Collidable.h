#ifndef collidable_h
#define collidable_h

#include "../SceneObjects/Hitbox.h"
#include "../Utils/Structures/Position3.h"
#include "../Utils/Structures/KDTree.h"
#include "../SceneObjects/Maps/Map.h"

class Collidable
{
private:
	KDTree* proximityTree;
	Map* map;

	vector<Position3> points;

	void populatePoints()
	{
		vector<Hitbox> hitboxes = map->getHitboxes();
		vector<Hitbox>::iterator it;
		vector<Position3>::iterator it2;

		for(it = hitboxes.begin(); it != hitboxes.end(); ++it)
		{
			vector<Position3>& verts = it->getVertices();
			for(it2 = verts.begin(); it2 != verts.end(); ++it2)
				points.push_back(*it2);
		}
	}
public:
	Collidable()
	{

	}

	Collidable(Map* m) : map(m)
	{
		populatePoints();
		proximityTree = new KDTree(points);

		vector<Position3> closestPoints = proximityTree->getTraversal();
	}

};

#endif
