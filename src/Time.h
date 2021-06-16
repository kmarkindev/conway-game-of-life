#pragma once

#include <glfw/glfw3.h>

class Time
{
public:
    Time();
    float GetDeltaTime();
    void UpdateDeltaTime();
    void ResetDeltaTime();
private:
    float _lastDeltaTimeRecordedAt;
    float _currentDeltaTime;
};


