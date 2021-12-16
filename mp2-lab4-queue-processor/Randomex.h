#pragma once
#include <cstdlib>

ref class Randomex
{
private:
	System::Random^ rand01;
public:

	Randomex()
	{
		srand(time(NULL));
		rand01 = gcnew System::Random();
	}

	//Generates random int in [rangeMin, rangeMax]
	int RandInt(int rangeMin, int rangeMax)
	{
		return (int)((double)rand() / (RAND_MAX + 1) * (rangeMax - rangeMin) + rangeMin);
	}

	bool RandBool(double probability)
	{
		return rand01->NextDouble() < probability;
	}
};