#ifndef updater_h
#define updater_h

#include "../Graphics/Glut/GlutDisplay.h"
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
	Updater(GlutDisplay* display, EnvironmentUpdater* eUpdater);

	void updateFunction()
	{
		frames++;

		microTimer.stopMicroTimer();
		deltaTime = microTimer.getDeltaTime();
		microTimer.startMicroTimer();

		display->updateCamera();
		envUpdater->updateEntities(deltaTime);

		glutPostRedisplay();
	}

	float getFPS()
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
