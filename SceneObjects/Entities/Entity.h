#ifndef entity_h
#define entity_h

#include <iostream>
#include "../../Physics/Movable.h"

using std::string;

class Entity : public Movable
{
protected:
	string name;
	Vector3 lookDirection;

public:
	Entity(const string& nom) :
		name(nom)
	{
	}

	const string& getName()
	{
		return name;
	}

	const Vector3& getLookDirection()
	{
		return lookDirection;
	}

	void setName(const string& nom)
	{
		name = nom;
	}

	void setLookDirection(const Vector3& look)
	{
		lookDirection = look;
	}
};

#endif
