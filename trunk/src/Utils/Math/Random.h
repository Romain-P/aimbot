#ifndef random_h
#define random_h

#include <cmath>
#include <cstdlib>

class Random
{
public:
	Random()
	{
		srand(time(0));
	}

	static inline int randomInt(int lowerBound, int upperBound)
	{
		return rand() % (upperBound - lowerBound) + lowerBound;
	}

	static inline float randomFloat()
	{
		return rand() / float(INT_MAX);
	}

	//maybe add some other more useful types of 'noisy' number generation

};

#endif
