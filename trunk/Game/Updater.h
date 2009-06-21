#ifndef updater_h
#define updater_h

#include "../Graphics/GlutDisplay.h"
#include "../Utils/Misc/MicroTimer.h"

class Updater
{
private:
	float deltaTime;
	long frames;
	MicroTimer microTimer;

	GlutDisplay* display;

public:

	Updater(GlutDisplay* display);

	static void updateDelegate();

	void updateFunction()
	{
		frames++;
		microTimer.stopMicroTimer();
		deltaTime = microTimer.getDeltaTime();
		microTimer.startMicroTimer();

		display->updateCamera();
		glutPostRedisplay();
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
