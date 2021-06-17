#pragma once

#include <glad/glad.h>
#include <exception>
#include <glm/glm.hpp>

#include "../Window.h"

class RenderAPI
{
public:
    RenderAPI();
    void SetViewport(glm::vec4 viewport);
    void SetClearColor(glm::vec3 color);
    void DrawArrays();
    void ClearColor();

    std::string GetOpenGlVersion();
};


