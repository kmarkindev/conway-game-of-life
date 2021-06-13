#include "SpawnCommand.h"

void SpawnCommand::ApplyTo(Field& field)
{
    field.SpawnCell(_position);
}

SpawnCommand::SpawnCommand(glm::ivec2 position)
    : _position(position)
{

}
