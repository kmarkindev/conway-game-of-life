#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <imgui.h>
#include <backends/imgui_impl_glfw.h>
#include <backends/imgui_impl_opengl3.h>

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
    window.SetTitle("Game of Life");
    auto renderApi = RenderAPI();
    auto time = Time();
    auto random = Random();
    random.SetSeed(7788);
    auto fieldSeeder = FieldSeeder(random);
    auto camera = Camera();
    auto fieldRenderer = FieldRenderer(&renderApi, &camera);

    ImGui::CreateContext();
    ImGuiIO& io = ImGui::GetIO();
    ImGui::StyleColorsDark();
    ImGui_ImplGlfw_InitForOpenGL(window.GetGlfwWindow(), true);
    ImGui_ImplOpenGL3_Init(renderApi.GetOpenGlVersion().c_str());

    std::vector<std::shared_ptr<IRule>> rules = {
            std::make_shared<KillLessThanTwo>(),
            std::make_shared<KillMoreThanThree>(),
            std::make_shared<SpawnWithThree>()
    };

    window.SetSize({800, 800});
    renderApi.SetViewport({0, 0, 800, 800});
    renderApi.SetClearColor({0.04f,0.00f,0.11f});

    auto field = Field({-20, 20, 20, -20});
    fieldSeeder.ApplySeed(field);

    time.ResetDeltaTime();

    float timeoutLimit = 1.0f;
    float timeout = 0.0f;
    bool shouldMakeSteps = false;
    bool runOnce = false;
    bool enableNoBoundsMode = false;

    while(!window.GetShouldClose())
    {
        window.PollEvents();
        ImGui_ImplOpenGL3_NewFrame();
        ImGui_ImplGlfw_NewFrame();
        ImGui::NewFrame();

        // UI

        ImGui::SetNextWindowBgAlpha(0.5f);
        ImGui::Begin("Menu");

        if(ImGui::Checkbox("Enable no bounds mode##enablenoboundsmode", &enableNoBoundsMode))
        {
            field.SetNoBounds(enableNoBoundsMode);
        }

        if(ImGui::Checkbox("##shouldrunsteps", &shouldMakeSteps))
        {
            timeout = 0.0f;
        }
        ImGui::SameLine();
        ImGui::Text("Time before step: %.2f / ", timeout);
        ImGui::SameLine();
        ImGui::PushItemWidth(40.0f);
        ImGui::DragFloat("##timeoutlimit", &timeoutLimit, 0.01f, 0.0f, 0.0f, "%.2f");

        ImGui::NewLine();

        if(ImGui::Button("Next step"))
        {
            runOnce = true;
        }

        if(ImGui::Button("Generate new field"))
        {
            fieldSeeder.ApplySeed(field);
        }

        ImGui::End();

        // Rules and Commands

        if(shouldMakeSteps)
            timeout += time.GetDeltaTime();

        if(runOnce || (shouldMakeSteps && timeout > timeoutLimit))
        {
            timeout = 0.0f;

            std::vector<std::shared_ptr<ICommand>> commands;

            for(auto& rule : rules)
            {
                auto newCommands = rule->ApplyTo(field);
                commands.insert(commands.end(), newCommands.begin(), newCommands.end());
            }

            for(auto& command : commands)
            {
                command->ApplyTo(field);
            }

            runOnce = false;
        }

        ImGui::Render();

        renderApi.ClearColor();
        fieldRenderer.Render(field);
        ImGui_ImplOpenGL3_RenderDrawData(ImGui::GetDrawData());

        time.UpdateDeltaTime();
        window.SwapBuffers();
    }

    ImGui_ImplOpenGL3_Shutdown();
    ImGui_ImplGlfw_Shutdown();
    ImGui::DestroyContext();
}