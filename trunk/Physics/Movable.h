#ifndef movable_h
#define movable_h

#include "../Utils/Structures/Position3.h"
#include "../Utils/Structures/Vector3.h"

/*
 * Base class for all movable objects
 */
class Movable
{
private:
public:
	Position3 start;
	Position3 displacement;
	Vector3 velocity;
	Vector3 acceleration;

	Movable()
	{
	}

	void move(float timeStep)
	{
		if(timeStep <= 0) return;

		velocity += acceleration * timeStep;
		displacement += velocity * timeStep;
	}

	Position3 getPosition()
	{
		return displacement + start;
	}
};

#endif
