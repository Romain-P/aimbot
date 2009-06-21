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
	Position3 position;
	Vector3 velocity;
	Vector3 acceleration;

	Movable()
	{
	}

	void move(float timeStep)
	{
		if(timeStep <= 0) return;

		velocity += acceleration * timeStep;
		position += velocity * timeStep;
	}
};

#endif
