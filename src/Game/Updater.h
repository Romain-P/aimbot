#ifndef updater_h
#define updater_h

#include "../Graphics/Glut/GlutDisplay.h"
#include "../Graphics/Animation/Animator.h"
#include "../Utils/Misc/MicroTimer.h"
#include "../Physics/EnvironmentUpdater.h"

class Updater
{
private:
	float deltaTime;
	long frames;
	MicroTimer microTimer;

	GlutDisplay* display;
	Animator* animator;
	EnvironmentUpdater* environmentUpdater;

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
