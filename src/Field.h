#pragma once

#include <vector>
#include <glm/glm.hpp>
#include <algorithm>

#include "Cell.h"

class Field
{
public:
    explicit Field(glm::ivec2 size);

    bool HasActiveCell(glm::ivec2 position);
    void KillCell(glm::ivec2 position);
    void SpawnCell(glm::ivec2 position);
    std::vector<Cell>::const_iterator Begin();
    std::vector<Cell>::const_iterator End();

private:
    glm::ivec2 _size;
    std::vector<Cell> _active_cells;

    auto FindCell(glm::ivec2 position);
};


