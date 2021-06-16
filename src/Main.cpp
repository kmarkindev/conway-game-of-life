#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Renderer/RenderAPI.h"
#include "Renderer/FieldRenderer.h"
#include "Renderer/Camera.h"
#include "Time.h"
#include "Random.h"
#include "Field.h"
#include "FieldSeeder.h"

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

    window.SetSize({800, 800});
    renderApi.SetViewport({0, 0, 800, 800});
    renderApi.SetClearColor({0.04f,0.00f,0.11f});

    auto field = Field({-10, 10, 10, -10});
    fieldSeeder.ApplySeed(field);

    time.ResetDeltaTime();

    while(!window.GetShouldClose())
    {
        window.PollEvents();

        renderApi.ClearColor();

        fieldRenderer.Render(field);

        time.UpdateDeltaTime();
        window.SwapBuffers();
    }
}