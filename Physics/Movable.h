#ifndef movable_h
#define movable_h

#include "../Utils/Structures/Vector3.h"

class Movable
{
private:
	Position3 position;
	Vector3 velocity;
	Vector3 acceleration;

public:
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
