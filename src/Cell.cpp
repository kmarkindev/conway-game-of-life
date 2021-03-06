#include "Cell.h"

Cell::Cell(Field& field, glm::ivec2 position)
    : _position(position), _field(field)
{

}

std::vector<glm::ivec2> Cell::GetNeighbors() const
{
    auto positions = std::vector<glm::ivec2>{
        _position + glm::ivec2(-1, 0),
        _position + glm::ivec2(-1, 1),
        _position + glm::ivec2(0, 1),
        _position + glm::ivec2(1, 1),
        _position + glm::ivec2(1, 0),
        _position + glm::ivec2(1, -1),
        _position + glm::ivec2(0, -1),
        _position + glm::ivec2(-1, -1)
    };

    for(auto& pos : positions)
    {
        pos = _field.GetPosition(pos);
    }

    return positions;
}

int Cell::GetNeighborsCount() const
{
    int neighborCount = 0;

    for(auto neighborPos : GetNeighbors())
    {
        if(_field.HasActiveCell(neighborPos))
            neighborCount++;
    }

    return neighborCount;
}

glm::ivec2 Cell::GetPosition() const
{
    return _position;
}

Cell& Cell::operator=(const Cell& cell)
{
    _position = cell._position;
    _field = cell._field;
    return *this;
}
