#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Renderer/RenderAPI.h"
#include "Renderer/FieldRenderer.h"
#include "Renderer/Camera.h"
#include "Time.h"
#include "Random.h"
#include "Field.h"
#include "FieldSeeder.h"
#include "Rules/IRule.h"
#include "Rules/KillLessThanTwo.h"
#include "Rules/KillMoreThanThree.h"
#include "Rules/SpawnWithThree.h"
#include "Commands/ICommand.h"
#include "Commands/SpawnCommand.h"
#include "Commands/KillCommand.h"

int main()
{
    auto window = Window();
    auto renderApi = RenderAPI();
    auto time = Time();
    auto random = Random();
    random.SetSeed(7788);
    auto fieldSeeder = FieldSeeder(random);
    auto camera = Camera();
    auto fieldRenderer = FieldRenderer(&renderApi, &camera);

    std::vector<std::shared_ptr<IRule>> rules = {
            std::make_shared<KillLessThanTwo>(),
            std::make_shared<KillMoreThanThree>(),
            std::make_shared<SpawnWithThree>()
    };

    window.SetSize({800, 800});
    renderApi.SetViewport({0, 0, 800, 800});
    renderApi.SetClearColor({0.04f,0.00f,0.11f});

    auto field = Field({-20, 20, 20, -20});
    field.SetNoBounds(true);
    fieldSeeder.ApplySeed(field);

    time.ResetDeltaTime();

    constexpr float timeoutLimit = 1.0f;
    float timeout = 0.0f;

    while(!window.GetShouldClose())
    {
        window.PollEvents();

        renderApi.ClearColor();

        timeout += time.GetDeltaTime();
        if(timeout > timeoutLimit)
        {
            timeout = 0.0f;

            std::vector<std::shared_ptr<ICommand>> commands;

            for(auto rule : rules)
            {
                auto newCommands = rule->ApplyTo(field);
                commands.insert(commands.end(), newCommands.begin(), newCommands.end());
            }

            for(auto command : commands)
            {
                command->ApplyTo(field);
            }
        }

        fieldRenderer.Render(field);

        time.UpdateDeltaTime();
        window.SwapBuffers();
    }
}