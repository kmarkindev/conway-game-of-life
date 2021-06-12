#pragma once

#include <glm/glm.hpp>

class Cell
{
public:
    explicit Cell(glm::ivec2 position);
private:
    glm::ivec2 _position;
};


