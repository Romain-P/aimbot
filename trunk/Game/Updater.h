#ifndef updater_h
#define updater_h

#include "../Utils/MicroTimer.h"

class Updater
{
private:
	long frames;
	float deltaTime;
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
};


#endif
