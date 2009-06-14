#ifndef environmentupdater_h
#define environmentupdater_h

#include <vector>
#include "PhysicalValue.h"
#include "../Entities/Player.h"

class EnvironmentUpdater
{
private:
	PhysicalValue* g;
	vector<Player*> players;
public:
	EnvironmentUpdater()
	{
		g = new PhysicalValue(-9.807, 1, 0, -2);
	}

	void updateEntities()
	{
		for(int i = 0; i < players.length(); i++)
		{

		}
	}

	void fallForTime(Entity* entity, float timeSlice)
	{

	}
};

#endif
