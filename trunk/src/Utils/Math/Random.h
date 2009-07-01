#ifndef random_h
#define random_h

#include <cmath>
#include <cstdlib>

class Random
{
public:
	static int randomInt(int lowerBound, int upperBound)
	{
		return rand() % (upperBound - lowerBound) + lowerBound;
	}

	static float randomFloat()
	{
		srand(time(0));
		return rand() / float(INT_MAX);
	}

	//maybe add some other more useful types of 'noisy' number generation

};

#endif
