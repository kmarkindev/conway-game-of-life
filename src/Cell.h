#pragma once

#include <glm/glm.hpp>
#include <stdexcept>
#include <vector>
#include "Field.h"

class Field;

class Cell
{
public:
    explicit Cell(Field& field, glm::ivec2 position);
    [[nodiscard]] std::vector<glm::ivec2> GetNeighbors() const;
    [[nodiscard]] int GetNeighborsCount() const;
    [[nodiscard]] glm::ivec2 GetPosition() const;

    Cell& operator=(const Cell& cell);
private:
    glm::ivec2 _position;
    Field& _field;
};


