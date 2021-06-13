#pragma once

#include <glm/glm.hpp>

#include "ICommand.h"
#include "../Field.h"

class SpawnCommand : ICommand
{
public:
    explicit SpawnCommand(glm::ivec2 position);
    void ApplyTo(Field& field) override;
private:
    glm::ivec2 _position;
};


