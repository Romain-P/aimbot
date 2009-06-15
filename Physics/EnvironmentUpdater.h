#ifndef environmentupdater_h
#define environmentupdater_h

#include <vector>
#include "PhysicalValue.h"
#include "../Entities/Entity.h"

class EnvironmentUpdater
{
private:
	PhysicalValue<float>* g;
	std::vector<Entity*> entities;
public:
	EnvironmentUpdater()
	{
		g = new PhysicalValue<float>(-9.807, 1, 0, -2);
	}

	void updateEntities()
	{
		/*
		float delta = updater->getDeltaTime();

		for(int i = 0; i < entities.length(); i++)
		{
			entities.at(i)->velocity.z += g * delta;
			entities.at(i)->position += entities.at(i)->velocity * delta;
		}
		*/
	}

	void fallForTime(Entity* entity, float timeSlice)
	{

	}
};

#endif
