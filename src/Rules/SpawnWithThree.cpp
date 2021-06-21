#include "SpawnWithThree.h"

std::vector<std::shared_ptr<ICommand>> SpawnWithThree::ApplyTo(const Field& field)
{
    auto commands = std::vector<std::shared_ptr<ICommand>>();

    std::map<std::pair<int, int>, int> deadCells;

    for(auto cell = field.Begin(); cell != field.End(); ++cell)
    {
        for(glm::ivec2 pos : cell->GetNeighbors())
        {
            auto position = std::make_pair(pos.x, pos.y);
            if(deadCells.contains(position))
            {
                deadCells[position] = deadCells[position] + 1;
            }
            else
            {
                deadCells.insert({position, 1});
            }
        }
    }

    for(auto const& [pos, count] : deadCells)
    {
        glm::ivec2 position = {std::get<0>(pos), std::get<1>(pos)};
        if(count == 3)
        {
            std::shared_ptr<ICommand> command =
                    std::dynamic_pointer_cast<ICommand>(std::make_shared<SpawnCommand>(position));

            commands.push_back(command);
        }
    }

    return commands;
}
