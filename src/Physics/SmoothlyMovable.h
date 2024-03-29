#ifndef smoothlymovable_h
#define smoothlymovable_h

#include "Movable.h"

class SmoothlyMovable : public Movable
{
private:
	// should be between 0.02 and 0.2 for best results
	float smoothness;

public:
	Vector3 destination;

	SmoothlyMovable(float smooth) :
		smoothness(smooth)
	{
	}

	void move(float timeStep)
	{
		if(timeStep <= 0) return;

		velocity += acceleration * timeStep;
		destination += velocity * timeStep;

		displacement += (destination - displacement) * smoothness;
	}
};

#endif
