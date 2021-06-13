#include "SpawnWithThree.h"

std::vector<std::shared_ptr<ICommand>> SpawnWithThree::ApplyTo(Field& field)
{
    auto commands = std::vector<std::shared_ptr<ICommand>>();

    auto comp = [](const glm::ivec2& c1, const glm::ivec2& c2){
        return (c1.x < c2.x && c1.y < c2.y);
    };

    std::map<glm::ivec2, int, decltype(comp)> deadCells;

    for(auto iter = field.Begin(); iter != field.End(); ++iter)
    {
        Cell cell = *iter;

        for(glm::ivec2 pos : cell.GetNeighbors())
        {
            if(deadCells.contains(pos))
            {
                deadCells[pos] = deadCells[pos]++;
            }
            else
            {
                deadCells.insert({pos, 1});
            }
        }
    }

    for(auto const& [pos, count] : deadCells)
    {
        if(count == 3)
        {
            std::shared_ptr<ICommand> command =
                    std::dynamic_pointer_cast<ICommand>(std::make_shared<SpawnCommand>(pos));

            commands.push_back(command);
        }
    }

    return commands;
}
