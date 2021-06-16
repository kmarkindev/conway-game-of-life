#pragma once

#include <random>

class Random
{
public:
    explicit Random();
    void SetSeed(unsigned int seed);
    float GetFloat01();

private:
    std::mt19937 _generator;
    std::uniform_real_distribution<float> _distrib01;
};


