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

public:
	Animatable() :
		animating(false),
		duration(1.f),
		samples(15)
	{
	}

	Animatable(float d, int s) :
		animating(false),
		duration(d),
		samples(s)
	{
	}

	void startAnimation()
	{
		animating = true;
	}

	void draw()
	{
		if(animating)
		{

		}
	}

	virtual void move(float timestep) = 0;
};

#endif
