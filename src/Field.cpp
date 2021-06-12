#include "Field.h"

Field::Field(glm::ivec2 size)
    : _size(size)
{

}

auto Field::FindCell(glm::ivec2 position)
{
    auto samePosition = [&position](Cell cell){
        return true;
    };

    return std::ranges::find_if(_active_cells.begin(), _active_cells.end(), samePosition);
}

bool Field::HasActiveCell(glm::ivec2 position)
{
    return FindCell(position) != _active_cells.end();
}

void Field::KillCell(glm::ivec2 position)
{
    auto cellIter = FindCell(position);
    _active_cells.erase(cellIter);
}

void Field::SpawnCell(glm::ivec2 position)
{
    if(!HasActiveCell(position))
    {
        _active_cells.push_back(Cell(position));
    }
}
