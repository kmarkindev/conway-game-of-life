#include "FieldSeeder.h"

void FieldSeeder::ApplySeed(Field& field)
{
    field.Clear();
    auto size = field.GetFieldSize();

    /*
     * It may be a really bad way to generate cells
     * but at least it's working
     */

    int count = 0;

    for(int x = size.x; x < size.z; ++x)
    {
        for(int y = size.w; y < size.y; ++y)
        {
            float gen = _random.GetFloat01();
            if(gen > 0.9)
            {
                field.SpawnCell({x, y});
                count++;
            }
        }
    }

    //just to make sure we have at least 1 generated cell
    if(count == 0)
        ApplySeed(field);
}

FieldSeeder::FieldSeeder(Random random)
 : _random(random)
{
}