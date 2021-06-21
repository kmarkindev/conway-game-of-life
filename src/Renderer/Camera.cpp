#include "Camera.h"

glm::ivec2 Camera::GetPosition() const
{
    return _position;
}

void Camera::SetPosition(const glm::ivec2& position)
{
    _position = position;
}

float Camera::GetZoom() const
{
    return _zoom;
}

void Camera::SetZoom(float zoom)
{
    if(zoom <= 0)
        throw std::invalid_argument("Zoom cannot be equal or less than 0");

    _zoom = zoom;
}

Camera::Camera()
    : _zoom(20.5f), _position({0, 0})
{
}

glm::mat4 Camera::GetProjectionMatrix() const
{
    return glm::ortho(-_zoom, _zoom,
                      _zoom, -_zoom,
                      0.0f, 1.0f);
}
