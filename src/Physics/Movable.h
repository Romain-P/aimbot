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

	Movable(Position3 start)
	{
		this->start = start;
	}

	Position3 getPosition()
	{
		return displacement + start;
	}

	Position3 getProjectedPosition(float timeAhead)
	{
		return getPosition() + velocity * timeAhead;
	}

	virtual void updateVelocity(const Vector3& v)
	{
		velocity = v;
	}

	virtual void move(float timeStep)
	{
		if(timeStep <= 0) return;
		displacement += velocity * timeStep;
	}
};

#endif
