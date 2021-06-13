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
    if(HasActiveCell(position))
    {
        auto cellIter = FindCell(position);
        _active_cells.erase(cellIter);
    }
}

void Field::SpawnCell(glm::ivec2 position)
{
    if(!HasActiveCell(position))
    {
        _active_cells.emplace_back(position);
    }
}

std::vector<Cell>::const_iterator Field::Begin()
{
    return _active_cells.begin();
}

std::vector<Cell>::const_iterator Field::End()
{
    return _active_cells.end();
}
