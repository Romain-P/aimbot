#ifndef environmentupdater_h
#define environmentupdater_h

#include <vector>
#include "Movable.h"
#include "PhysicalValue.h"
#include "../SceneObjects/Entities/Entity.h"

using std::vector;

class EnvironmentUpdater
{
private:
	PhysicalValue<float>* g;
	//vector<Entity*> entities;
	vector<Movable*> movables;
public:
	EnvironmentUpdater()
	{
		g = new PhysicalValue<float>(-9.807f, 1, 0, -2);
	}

	~EnvironmentUpdater()
	{
		delete g;
	}

	void updateEntities(float timeStep)
	{
		static vector<Movable*>::const_iterator it;
		for(it = movables.begin(); it != movables.end(); ++it)
		{
			(*it)->move(timeStep);
		}
	}

	void addMovable(Movable* movable)
	{
		movables.push_back(movable);
	}

};

#endif
