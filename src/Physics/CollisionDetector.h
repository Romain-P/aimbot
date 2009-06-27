#ifndef collisiondetector_h
#define collisiondetector_h

#include "../SceneObjects/Mesh.h"

class CollisionDetector
{
private:
public:
	CollisionDetector()
	{

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
