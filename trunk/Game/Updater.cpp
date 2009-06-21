#include "Updater.h"

Updater* updater;

Updater::Updater(GlutDisplay* glutDisplay, EnvironmentUpdater* eUpdater) :
	deltaTime(0),
	frames(0)
{
	display = glutDisplay;
	updater = this;
	envUpdater = eUpdater;

	microTimer.startMicroTimer();
}

void Updater::updateDelegate()
{
	updater->updateFunction();
}
