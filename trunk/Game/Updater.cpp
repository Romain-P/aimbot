#include "Updater.h"

Updater* updater;

Updater::Updater()
{
	updater = this;

	fps = 1;
	microTimer.startMicroTimer();
}

void updateDelegate()
{
	updater->updateFunction();
}
