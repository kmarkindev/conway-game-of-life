#include "RenderAPI.h"

RenderAPI::RenderAPI()
{
    if(!gladLoadGL())
        std::terminate();
}

void RenderAPI::SetViewport(glm::vec4 viewport)
{
    glViewport(viewport[0], viewport[1], viewport[2], viewport[3]);
}

void RenderAPI::SetClearColor(glm::vec3 color)
{
    glClearColor(color[0], color[1], color[2], 1.0f);
}

void RenderAPI::ClearColor()
{
    glClear(GL_COLOR_BUFFER_BIT | GL_DEPTH_BUFFER_BIT);
}

void RenderAPI::DrawArrays()
{
    //we only use quads
    //it means there always be 6 vertices
    glDrawArrays(GL_TRIANGLES, 0, 6);
}
