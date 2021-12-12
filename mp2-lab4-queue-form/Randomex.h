#pragma once
#include <cstdlib>
#include <time.h>

public class Randomex {

private:
    Randomex() {}
public:

    static void Prepare() {
        srand(time(NULL));
    }

    //RangeMin <= RandInt(RangeMin, RangeMax) < RangeMax
    static int RandInt(int RangeMin, int RangeMax)
    {
        return ((double)rand() / (RAND_MAX + 1) * (RangeMax - RangeMin) + RangeMin);
    }

    //Result will be true with probability
    static bool RandBool(float probability)
    {
        return rand() < probability * ((double)RAND_MAX + 1.0);
    }
};