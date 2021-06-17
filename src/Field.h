#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <stdexcept>
#include <algorithm>

#include "Cell.h"

class Cell;

class Field
{
public:
    explicit Field(glm::ivec4 fieldSize);

    bool HasActiveCell(glm::ivec2 position);
    void KillCell(glm::ivec2 position);
    void SpawnCell(glm::ivec2 position);
    void Clear();

    glm::ivec4 GetFieldSize();
    bool HasPosition(glm::ivec2 position);
    glm::ivec2 GetPosition(glm::ivec2 position);

    bool GetNoBounds();
    void SetNoBounds(bool value);

    std::vector<Cell>::iterator Begin();
    std::vector<Cell>::iterator End();

private:
    glm::ivec4 _size;
    std::vector<Cell> _active_cells;
    bool _noBound;

    auto FindCell(glm::ivec2 position);
    bool CorrectFieldSize(glm::ivec4 size);
};


