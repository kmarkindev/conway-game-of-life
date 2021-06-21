#pragma once

#include <map>

#include "IRule.h"
#include "../Commands/SpawnCommand.h"

class SpawnWithThree : public IRule
{
    std::vector<std::shared_ptr<ICommand>> ApplyTo(const Field& field) override;
};


