#pragma once

#include "../Field.h"

class ICommand
{
public:
    virtual void ApplyTo(Field& field) = 0;
};