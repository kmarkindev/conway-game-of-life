#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>

class Camera
{
public:
    Camera();

    glm::ivec2 GetPosition();
    void SetPosition(const glm::ivec2& position);
    float GetZoom();
    void SetZoom(float zoom);
    glm::mat4 GetProjectionMatrix();

private:
    glm::ivec2 _position;
    float _zoom;
};


