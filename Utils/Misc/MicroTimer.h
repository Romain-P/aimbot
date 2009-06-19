#ifndef microtimer_h
#define microtimer_h

#include <windows.h>
#include <stdio.h>

class MicroTimer
{
private:
	LARGE_INTEGER ticksPerSecond;
	LARGE_INTEGER tick1;
	LARGE_INTEGER tick2;

public:
	MicroTimer()
	{
		QueryPerformanceFrequency(&ticksPerSecond);
	}

	/**
	 *
	 * Put this before a function call ...
	 */
	void startMicroTimer()
	{
		QueryPerformanceCounter(&tick1);
	}

	/**
	 *
	 * ...And this directly after, then call...
	 */
	void stopMicroTimer()
	{
		QueryPerformanceCounter(&tick2);
	}

	/**
	 * ...this, and you have the time it took in seconds, microsecond accurate.
	 */
	double getDeltaTime()
	{
		return (tick2.QuadPart - tick1.QuadPart) / double(ticksPerSecond.QuadPart);
	}
};

#endif
