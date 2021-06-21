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

    [[nodiscard]] bool HasActiveCell(glm::ivec2 position) const;
    void KillCell(glm::ivec2 position);
    void SpawnCell(glm::ivec2 position);
    void Clear();

    [[nodiscard]] glm::ivec4 GetFieldSize() const;
    [[nodiscard]] bool HasPosition(glm::ivec2 position) const;
    [[nodiscard]] glm::ivec2 GetPosition(glm::ivec2 position) const;

    [[nodiscard]] bool GetNoBounds() const;
    void SetNoBounds(bool value);

    [[nodiscard]] std::vector<Cell>::iterator Begin();
    [[nodiscard]] std::vector<Cell>::iterator End();

    [[nodiscard]] std::vector<Cell>::const_iterator Begin() const;
    [[nodiscard]] std::vector<Cell>::const_iterator End() const;

private:
    glm::ivec4 _size;
    std::vector<Cell> _active_cells;
    bool _noBound;

    [[nodiscard]] auto FindCell(glm::ivec2 position) const;
    [[nodiscard]] bool CorrectFieldSize(glm::ivec4 size) const;
};


