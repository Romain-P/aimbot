#ifndef updater_h
#define updater_h

#include "../Utils/Misc/MicroTimer.h"

class Updater
{
private:
	float deltaTime;
	long frames;
	MicroTimer microTimer;

public:

	Updater();

	static void updateDelegate();

	void updateFunction()
	{
		frames++;
		microTimer.stopMicroTimer();
		deltaTime = microTimer.getDeltaTime();
		microTimer.startMicroTimer();

		// update physics and stuff
	}

	float getFps()
	{
		return 1 / deltaTime;
	}

	long getFrames()
	{
		return frames;
	}

	float getDeltaTime()
	{
		return deltaTime;
	}
};


#endif
