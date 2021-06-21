#pragma once

#include <glfw/glfw3.h>

class Time
{
public:
    Time();
    [[nodiscard]] float GetDeltaTime() const;
    void UpdateDeltaTime();
    void ResetDeltaTime();
private:
    float _lastDeltaTimeRecordedAt;
    float _currentDeltaTime;
};


