#pragma once

#include <glm/glm.hpp>
#include <stdexcept>
#include <vector>
#include "Field.h"

class Field;

class Cell
{
public:
    explicit Cell(Field* field, glm::ivec2 position);
    std::vector<glm::ivec2> GetNeighbors();
    int GetNeighborsCount();
    glm::ivec2 GetPosition();
private:
    glm::ivec2 _position;
    Field* _field;
};


