#pragma once

#include "IRule.h"
#include "../Commands/KillCommand.h"

class KillMoreThanThree : public IRule
{
    std::vector<std::shared_ptr<ICommand>> ApplyTo(const Field& field) override;
};


