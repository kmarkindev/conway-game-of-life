#include "KillCommand.h"

void KillCommand::ApplyTo(Field& field)
{
    field.KillCell(_position);
}

KillCommand::KillCommand(glm::ivec2 position)
    : _position(position)
{

}
