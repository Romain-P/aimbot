#ifndef updater_h
#define updater_h

#include "../Utils/MicroTimer.h"

class Updater
{
private:
	float deltaTime;
	MicroTimer microTimer;

public:
	Updater();

	static void updateDelegate();

	void updateFunction()
	{
		microTimer.stopMicroTimer();
		deltaTime = microTimer.getDeltaTime();
		microTimer.startMicroTimer();

		// update physics and stuff
	}

	float getFps()
	{
		return 1 / deltaTime;
	}
};


#endif
