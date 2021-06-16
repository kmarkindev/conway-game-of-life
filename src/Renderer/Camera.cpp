#include "Camera.h"

glm::ivec2 Camera::GetPosition()
{
    return _position;
}

void Camera::SetPosition(const glm::ivec2& position)
{
    _position = position;
}

float Camera::GetZoom()
{
    return _zoom;
}

void Camera::SetZoom(float zoom)
{
    _zoom = zoom;
}

Camera::Camera()
    : _zoom(20.5f), _position({0, 0})
{
}

glm::mat4 Camera::GetProjectionMatrix()
{
    return glm::ortho(-_zoom, _zoom,
                      _zoom, -_zoom,
                      0.0f, 1.0f);
}
