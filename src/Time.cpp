#include "Time.h"

float Time::GetDeltaTime() const
{
    return _currentDeltaTime;
}

void Time::UpdateDeltaTime()
{
    auto currentTime = (float)glfwGetTime();
    _currentDeltaTime = currentTime - _lastDeltaTimeRecordedAt;
    _lastDeltaTimeRecordedAt = currentTime;
}

Time::Time()
{
    ResetDeltaTime();
}

void Time::ResetDeltaTime()
{
    _lastDeltaTimeRecordedAt = 0.0f;
    _currentDeltaTime = 0.0f;
}
