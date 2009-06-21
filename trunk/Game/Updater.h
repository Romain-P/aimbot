#ifndef updater_h
#define updater_h

#include "../Graphics/GlutDisplay.h"
#include "../Utils/Misc/MicroTimer.h"
#include "../Physics/EnvironmentUpdater.h"

class Updater
{
private:
	float deltaTime;
	long frames;
	MicroTimer microTimer;

	EnvironmentUpdater* envUpdater;
	GlutDisplay* display;

public:
	Updater(GlutDisplay* display);

	void updateFunction()
	{
		frames++;

		microTimer.stopMicroTimer();
		deltaTime = microTimer.getDeltaTime();
		microTimer.startMicroTimer();

		display->updateCamera();
		envUpdater->updateEntities(deltaTime);

		if(frames % 60 == 0)
			std::cout << getFps() << std::endl;

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

	static void updateDelegate();
};


#endif
