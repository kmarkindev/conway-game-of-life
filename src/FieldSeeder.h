#pragma once

#include <stdexcept>

#include "Field.h"
#include "Random.h"

class FieldSeeder
{
public:
    explicit FieldSeeder(Random random);
    void ApplySeed(Field& field);
private:
    Random _random;
};


