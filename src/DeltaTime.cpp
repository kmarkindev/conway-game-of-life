#include "DeltaTime.h"

float DeltaTime::GetDeltaTime() const
{
    return _currentDeltaTime;
}

void DeltaTime::UpdateDeltaTime()
{
    auto currentTime = (float)glfwGetTime();
    _currentDeltaTime = currentTime - _lastDeltaTimeRecordedAt;
    _lastDeltaTimeRecordedAt = currentTime;
}

DeltaTime::DeltaTime()
{
    ResetDeltaTime();
}

void DeltaTime::ResetDeltaTime()
{
    _lastDeltaTimeRecordedAt = 0.0f;
    _currentDeltaTime = 0.0f;
}
