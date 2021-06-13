#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>

#include "Renderer/RenderAPI.h"
#include "Window.h"
#include "Renderer/VertexBuffer.h"
#include "Renderer/VertexArray.h"
#include "Renderer/Shader.h"

std::string vertextSrc = R"(
#version 330 core

layout (location = 0) in vec2 Vert;

uniform mat4 matrix;

void main()
{
    gl_Position = matrix * vec4(Vert.x, Vert.y, 0, 1);
}
)";

std::string fragmentSrc = R"(
#version 330 core

out vec4 Color;

void main()
{
    Color = vec4(1, 1, 1, 1);
}
)";

int main()
{
    auto window = Window();
    auto renderApi = RenderAPI();

    renderApi.SetViewport({0, 0, 800, 800});

    renderApi.SetClearColor({0.04f,0.00f,0.11f});

    auto shader = Shader(vertextSrc, fragmentSrc);
    auto vertexBuffer = VertexBuffer();
    auto vertexArray = VertexArray();

    vertexArray.AssignVertexBuffer(vertexBuffer);

    while(!window.GetShouldClose())
    {
        window.PollEvents();

        renderApi.ClearColor();

        shader.UseProgram();

        auto proj = glm::ortho(-10.5f, 10.5f, 10.5f, -10.5f, 0.0f, 1.0f);

        for(auto pos : {
            glm::vec3({0, 0, 0}),
            glm::vec3({1, 0, 0}),
            glm::vec3({3, 2, 0}),
            glm::vec3({1, -3, 0}),
            glm::vec3({7, 3, 0}),
            glm::vec3({-10, 10, 0})
        })
        {
            auto transform = proj * glm::translate(glm::mat4(1.0f), pos);
            shader.SetMat4("matrix", transform);

            vertexArray.Bind();
            renderApi.DrawArrays();
            vertexArray.Unbind();
        }

        window.SwapBuffers();
    }
}