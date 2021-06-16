#include "Random.h"

float Random::GetFloat01()
{
    return (float)_distrib01(_generator);
}

void Random::SetSeed(unsigned int seed)
{
    _generator.seed(seed);
}

Random::Random()
{
    _generator = std::mt19937();
    _distrib01 = std::uniform_real_distribution<float>(0, 1);
}
