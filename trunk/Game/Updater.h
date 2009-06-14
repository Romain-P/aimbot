#ifndef updater_h
#define updater_h

class Updater
{
private:
	float fps;
	MicroTimer microTimer;

public:
	Updater();

	static void updateDelegate();

	void updateFunction()
	{
		microTimer.stopMicroTimer();
		fps = 1 / microTimer.getDeltaTime();
		microTimer.startMicroTimer();

		// update physics and stuff
	}

	float getFps()
	{
		return fps;
	}
};


#endif
