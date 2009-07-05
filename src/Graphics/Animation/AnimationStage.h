#ifndef animationstage_h
#define animationstage_h

#include "../ScreenBoundsUser.h"

class AnimationStage : public ScreenBoundsUser
{
private:
	bool expired;
	float duration;

public:
	float timeElapsed;
	enum { INFINITE_TIME = 0xffff };

	AnimationStage(float d) :
		expired(0),
		duration(d),
		timeElapsed(0)
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
		if(timeElapsed > duration)
			std::cout << timeElapsed << " " << duration << std::endl;
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


#endif
