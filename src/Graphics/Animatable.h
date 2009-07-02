#ifndef animatable_h
#define animatable_h

#include "Drawable.h"

class AnimationStage
{
private:
	bool expired;
	float duration;

public:
	float timeElapsed;
	enum { INFINITE_TIME = 0xffff };

	AnimationStage(float d) :
		duration(d),
		timeElapsed(0),
		expired(0)
	{
	}

	/*
	 * The reason we're testing against a flag AND the elapsed time
	 * is that certain stages need to remain alive until an untimable
	 * event occurs, like a mouse click, and to do this we set the
	 * duration to INFINITE_TIME and handle the termination of the
	 * stage with the expired flag, which we can set at any point.
	 */
	bool hasExpired()
	{
		return expired || timeElapsed > duration;
	}

	float progress()
	{
		// multiplication is faster
		static float iDuration = 1 / duration;

		return timeElapsed * iDuration;
	}

	void setExpired()
	{
		expired = true;
	}

	virtual void animate() = 0;
	virtual void draw() = 0;
};

class Animatable : public Drawable
{
private:
	vector<AnimationStage>::iterator stageIter;

	void stopAnimation()
	{
		animating = false;
	}

protected:
	bool animating;

	vector<AnimationStage> stages;

public:
	Animatable() :
		animating(false)
	{
	}

	void startAnimation()
	{
		stageIter = stages.begin();
		animating = true;
	}

	void update(float timestep)
	{
		if(!animating)
			return;

		if(stageIter->hasExpired())
		{
			if(stageIter == stages.end())
			{
				stopAnimation();
				return;
			}
			++stageIter;
		}
		else
		{
			stageIter->timeElapsed += timestep;
		}

		animate();
	}

	void expireStage()
	{
		stageIter->setExpired();
	}

	void draw()
	{
		stageIter->draw();
	}

	void animate()
	{
		stageIter->animate();
	}
};

#endif
