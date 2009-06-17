#ifndef successanalyser_h
#define successanalyser_h

#include "Utils/NeuralNetwork.h"

class SuccessAnalyser
{
private:
	float sampleDeltaTime;
	NeuralNetwork* network;
public:
	SuccessAnalyser(deltaTime) : sampleDeltaTime(deltaTime)
	{
	}

	void begin()
	{
	}

	void end()
	{
	}
};

#endif
