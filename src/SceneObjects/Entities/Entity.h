#ifndef entity_h
#define entity_h

#include <iostream>
#include "../../Physics/Movable.h"
#include "../../Physics/Collidable.h"

using std::string;

class Entity :
	public Movable,
	public Collidable
{
protected:
	string name;
	Vector3 lookDirection;

public:
	Entity(const string& nom) :
		name(nom)
	{
	}

	virtual ~Entity()
	{
	}

	const string& getName()
	{
		return name;
	}
};

#endif
