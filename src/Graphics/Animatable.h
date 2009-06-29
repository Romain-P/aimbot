#ifndef animatable_h
#define animatable_h

#include "Drawable.h"

class Animatable : public Drawable
{
private:

	void stopAnimation()
	{
		animating = false;
		timeElapsed = 0;
	}
protected:
	bool animating;
	float duration;
	float timeElapsed;

	virtual void draw() = 0;
	virtual void animate() = 0;

	float progress()
	{
		return timeElapsed / duration;
	}

public:
	Animatable() :
		animating(false),
		duration(1.f),
		timeElapsed(0)
	{
	}

	Animatable(float d) :
		animating(false),
		duration(d),
		timeElapsed(0)
	{
	}

	void startAnimation()
	{
		animating = true;
	}

	void update(float timestep)
	{
		if(!animating)
			return;

		if(timeElapsed > duration)
		{
			stopAnimation();
			return;
		}

		timeElapsed += timestep;
		animate();
	}
};

#endif
