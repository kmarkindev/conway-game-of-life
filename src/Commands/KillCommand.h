#pragma once

#include "glm/glm.hpp"

#include "ICommand.h"
#include "../Field.h"

class KillCommand : public ICommand
{
public:
    explicit KillCommand(glm::ivec2 position);
    void ApplyTo(Field& field) override;
private:
    glm::ivec2 _position;
};


