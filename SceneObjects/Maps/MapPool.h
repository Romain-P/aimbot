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

	void removeMapFromRotation(Map* map)
	{
		int i;
		for(i = 0; i < pool.size(); i++)
			if(map == pool.at(i) && i < pool.size() - 1)
				break;
		if(i < pool.size() - 1 || map == pool.at(i))
			pool.erase(pool.begin() + i);
	}
};

#endif
