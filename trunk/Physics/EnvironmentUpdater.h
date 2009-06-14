#ifndef environmentupdater_h
#define environmentupdater_h

#include <vector>
#include "PhysicalValue.h"
#include "../Entities/Entity.h"

class EnvironmentUpdater
{
private:
	PhysicalValue* g;
	vector<Entity*> entities;
public:
	EnvironmentUpdater()
	{
		g = new PhysicalValue(-9.807, 1, 0, -2);
	}

	void updateEntities()
	{
		for(int i = 0; i < entities.length(); i++)
		{

		}
	}

	void fallForTime(Entity* entity, float timeSlice)
	{

	}
};

#endif
