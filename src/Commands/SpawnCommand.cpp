#include "SpawnCommand.h"

void SpawnCommand::ApplyTo(Field& field)
{
    auto positionToSpawn = field.GetPosition(_position);
    field.SpawnCell(positionToSpawn);
}

SpawnCommand::SpawnCommand(glm::ivec2 position)
    : _position(position)
{

}