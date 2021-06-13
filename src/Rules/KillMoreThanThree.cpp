#include "KillMoreThanThree.h"

std::vector<std::shared_ptr<ICommand>> KillMoreThanThree::ApplyTo(Field& field)
{
    auto commands = std::vector<std::shared_ptr<ICommand>>();

    for(auto iter = field.Begin(); iter != field.End(); ++iter)
    {
        Cell cell = *iter;
        int neighborsCount = cell.GetNeighborsCount();

        if(neighborsCount > 3)
        {
            std::shared_ptr<ICommand> command =
                    std::dynamic_pointer_cast<ICommand>(std::make_shared<KillCommand>(cell.GetPosition()));

            commands.push_back(command);
        }
    }

    return commands;
}
