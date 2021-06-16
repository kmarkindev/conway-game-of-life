#include "Field.h"

Field::Field(glm::ivec4 fieldSize)
    : _size(fieldSize)
{
    if(!CorrectFieldSize(fieldSize))
        throw std::invalid_argument("Invalid field size params");
}

auto Field::FindCell(glm::ivec2 position)
{
    auto samePosition = [&position](Cell cell){
        return cell.GetPosition() == position;
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
    if(!HasPosition(position))
        throw std::invalid_argument(
                "Cannot spawn cell on this position because field does not have such position.");

    if(!HasActiveCell(position))
        _active_cells.push_back(Cell(this, position));
}

std::vector<Cell>::iterator Field::Begin()
{
    return _active_cells.begin();
}

std::vector<Cell>::iterator Field::End()
{
    return _active_cells.end();
}

glm::ivec4 Field::GetFieldSize()
{
    return _size;
}

bool Field::HasPosition(glm::ivec2 position)
{
    return _size.x <= position.x && position.x <= _size.z
        && _size.y >= position.y && position.y >= _size.w;
}

bool Field::CorrectFieldSize(glm::ivec4 size)
{
    return size.x < size.z
        && size.y > size.w;
}

void Field::Clear()
{
    _active_cells.empty();
}
