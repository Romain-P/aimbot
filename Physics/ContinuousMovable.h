#ifndef continuousmovable_h
#define continuousmovable_h

#include "Movable.h"

class ContinuousMovable : public Movable
{
private:
	// should be between 0.02 and 0.2 for best results
	float smoothness;

public:
	Vector3 destination;

	ContinuousMovable(float smooth) :
		smoothness(smooth)
	{
	}

	void move(float timeStep)
	{
		if(timeStep <= 0) return;

		velocity += acceleration * timeStep;
		destination += velocity * timeStep;

		position += (destination - position) * smoothness;
	}
};

#endif
