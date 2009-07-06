#ifndef collisiondetector_h
#define collisiondetector_h

#include <vector>
#include "../Utils/Structures/Position3.h"
#include "../SceneObjects/Meshes/Mesh.h"
#include "../SceneObjects/Meshes/Hitbox.h"
#include "../Utils/Structures/KDTree.h"

class CollisionDetector
{
private:

	float radius;
	vector<Position3> nearbyCentres;
	vector<Mesh> nearbyMeshes;

public:
	CollisionDetector()
	{
		radius = 100;
	}


	bool areCollided(Position3& p)
	{

		// get a list of all meshes somehow, or perhaps even a subset depending on how many there will be or how
		// computationally slow getting the list is

		vector<Mesh> allMeshes;

		for(int i = 0; i < allMeshes.size(); i++)
		{
			if (((allMeshes.at(i).getCentre().x - p.x) < radius) || ((allMeshes.at(i).getCentre().y - p.y) < radius) || ((allMeshes.at(i).getCentre().z - p.z) < radius))
			{
				nearbyCentres.push_back(allMeshes.at(i).getCentre());
			}
		}

		KDTree* tree = new KDTree(nearbyCentres);
		vector<Position3> traversal = tree->getTraversal();



		return false;
	}

	bool areCollided(Position3& p, Mesh* mesh)
	{



		return false;
	}

	inline bool areCollided(Hitbox* hitbox, Mesh* mesh)
	{
		return false;
	}

};

#endif
