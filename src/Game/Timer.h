#ifndef timer_h
#define timer_h

#include "Updater.h"

class Timer
{
private:
	int interval;
public:
	Timer(int ms) :
		interval(ms)
	{
	}
};

#endif
