#ifndef updater_h
#define updater_h

#include "../Graphics/Glut/GlutDisplay.h"
#include "../Graphics/Animator.h"
#include "../Utils/Misc/MicroTimer.h"
#include "../Physics/EnvironmentUpdater.h"

class Updater
{
private:
	float deltaTime;
	long frames;
	MicroTimer microTimer;

	GlutDisplay* display;
	EnvironmentUpdater* environmentUpdater;
	Animator* animator;

public:
	Updater(GlutDisplay* display,
			EnvironmentUpdater* envUpdater,
			Animator* animator);

	void updateFunction();
	float getFPS();
	long getFrames();
	float getDeltaTime();
	static void updateDelegate();
};


#endif
