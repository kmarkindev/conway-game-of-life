#pragma once

#include <string>
#include <glm/glm.hpp>
#include <GLFW/glfw3.h>

class Window
{
public:
    Window();
    ~Window();
    void SetSize(glm::ivec2 size);
    void SetFullScreen(bool enable);
    bool IsFullScreen();
    void SetTitle(const std::string& title);
    void SwapBuffers();
    void PollEvents();
    void SetShouldClose();
    bool GetShouldClose();

    GLFWwindow* GetGlfwWindow();
private:
    GLFWwindow* _window;
    GLFWmonitor* _primaryMonitor;
    glm::ivec2 _lastWindowPos;
    glm::ivec2 _lastWindowSize;
};


