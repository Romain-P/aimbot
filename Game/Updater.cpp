#include "Updater.h"

Updater* updater;

Updater::Updater() :
	deltaTime(0),
	frames(0)
{
	updater = this;
	microTimer.startMicroTimer();
}

void updateDelegate()
{
	updater->updateFunction();
}
