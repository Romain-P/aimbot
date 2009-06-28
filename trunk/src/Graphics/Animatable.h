#ifndef animatable_h
#define animatable_h

#include "Drawable.h"
#include "../Physics/Movable.h"

class Animatable : public Drawable, public Movable
{
private:
	bool animating;
	float duration;
	int samples;
	int samplePosition;

public:
	Animatable() :
		animating(false),
		duration(1.f),
		samples(15),
		samplePosition(0)
	{
	}

	Animatable(float d, int s) :
		animating(false),
		duration(d),
		samples(s),
		samplePosition(0)
	{
	}

	void startAnimation()
	{
		animating = true;
	}

	void move(float timestep)
	{
		if(animating)
		{
			update(timestep, samplePosition);
		}
	}

	virtual void draw() = 0;
	virtual void update(float timestep, int index) = 0;
};

#endif
