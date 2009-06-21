#include "Updater.h"

Updater* updater;

Updater::Updater(GlutDisplay* glutDisplay) :
	deltaTime(0),
	frames(0)
{
	display = glutDisplay;
	updater = this;
	envUpdater = new EnvironmentUpdater();

	microTimer.startMicroTimer();
}

void Updater::updateDelegate()
{
	updater->updateFunction();
}
