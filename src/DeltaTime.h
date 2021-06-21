#pragma once

#include <glfw/glfw3.h>

class DeltaTime
{
public:
    DeltaTime();
    [[nodiscard]] float GetDeltaTime() const;
    void UpdateDeltaTime();
    void ResetDeltaTime();
private:
    float _lastDeltaTimeRecordedAt;
    float _currentDeltaTime;
};


