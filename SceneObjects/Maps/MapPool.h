#ifndef mappool_h
#define mappool_h

#include <vector>
#include "Map.h"

using std::vector;

class MapPool
{
private:
	vector<Map *> pool;
public:
	MapPool()
	{

	}

	void addMapToRotation(Map* map)
	{
		pool.push_back(map);
	}
};

#endif
