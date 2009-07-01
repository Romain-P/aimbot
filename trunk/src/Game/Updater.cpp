#include "Updater.h"

Updater* updater;

Updater::Updater(GlutDisplay* glutDisplay, EnvironmentUpdater* envUpdater, Animator* anim) :
	deltaTime(0),
	frames(0),
	display(glutDisplay),
	animator(anim),
	environmentUpdater(envUpdater)
{
	updater = this;

	microTimer.startMicroTimer();
}

void Updater::updateDelegate()
{
	updater->updateFunction();
}

void Updater::updateFunction()
{
	frames++;

	microTimer.stopMicroTimer();
	deltaTime = microTimer.getDeltaTime();
	microTimer.startMicroTimer();

	display->updateCamera();
	environmentUpdater->updateEntities(deltaTime);
	animator->updateAnimations(deltaTime);

	glutPostRedisplay();
}

float Updater::getFPS()
{
	return 1 / deltaTime;
}

long Updater::getFrames()
{
	return frames;
}

float Updater::getDeltaTime()
{
	return deltaTime;
}
