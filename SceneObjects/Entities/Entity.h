#ifndef entity_h
#define entity_h

#include <iostream>

#include "../../Utils/Structures/Vector3.h"
#include "../../Utils/Structures/Position3.h"

using std::string;

class Entity
{
protected:
	string name;
	Vector3 lookDirection;

public:
	Position3 position;
	Vector3 velocity;

	Entity()
	{
		this->name = name;
	}

	string getName()
	{
		return name;
	}

	Position3 getPosition()
	{
		return position;
	}

	Vector3 getLookDirection()
	{
		return lookDirection;
	}

	Vector3 getVelocity()
	{
		return velocity;
	}


	void setName(string n)
	{
		name = n;
	}

	void setPosition(Position3 p)
	{
		position = p;
	}

	void setLookDirection(Vector3 l)
	{
		lookDirection = l;
	}

	void setVelocity(Vector3 v)
	{
		velocity = v;
	}

};

#endif