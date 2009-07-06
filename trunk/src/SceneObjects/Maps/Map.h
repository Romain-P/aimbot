#ifndef map_h
#define map_h

#include <string>

#include "MapObject.h"
#include "../SceneObject.h"
#include "../Meshes/Mesh.h"
#include "../Meshes/Hitbox.h"

class MapPool;

using std::string;
using std::vector;

class Map
{
private:
	vector<Hitbox> hitboxes;
public:
	Map(string& filename)
	{

	}

	const vector<Hitbox>& getHitboxes()
	{
		return hitboxes;
	}
};

#endif
