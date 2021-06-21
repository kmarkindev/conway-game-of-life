#pragma once

#include <glm/glm.hpp>
#include <glm/gtc/matrix_transform.hpp>
#include <stdexcept>

class Camera
{
public:
    Camera();

    [[nodiscard]] glm::ivec2 GetPosition() const;
    void SetPosition(const glm::ivec2& position);
    [[nodiscard]] float GetZoom() const;
    void SetZoom(float zoom);
    [[nodiscard]] glm::mat4 GetProjectionMatrix() const;

private:
    glm::ivec2 _position;
    float _zoom;
};


