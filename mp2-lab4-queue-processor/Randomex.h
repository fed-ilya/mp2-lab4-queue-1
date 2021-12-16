#pragma once
#include <cstdlib>

ref class Randomex {
private:
	static Random^ rand01 = gcnew Random();
	Randomex();
public:

	//Generates random int in [rangeMin, rangeMax]
	static int RandInt(int rangeMin, int rangeMax)
	{
		return (int) ((double)rand() / (RAND_MAX + 1) * (rangeMax - rangeMin) + rangeMin);
	}

	static bool RandBool(double probability)
	{
		return rand01->NextDouble() < probability;
	}
};