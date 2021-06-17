#include "Window.h"

Window::Window()
{
    if (!glfwInit())
        std::terminate();

    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 3);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 3);
    glfwWindowHint(GLFW_OPENGL_PROFILE, GLFW_OPENGL_CORE_PROFILE);
    glfwWindowHint(GLFW_CLIENT_API, GLFW_OPENGL_API);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_FALSE);

    _window = glfwCreateWindow(800, 800, "Title", nullptr, nullptr);

    glfwMakeContextCurrent(_window);

    _primaryMonitor = glfwGetPrimaryMonitor();
}

void Window::SetSize(glm::ivec2 size)
{
    if(IsFullScreen())
        return;

    glfwSetWindowSize(_window, size[0], size[1]);
}

void Window::SetFullScreen(bool enable)
{
    const GLFWvidmode* vidMode = glfwGetVideoMode(_primaryMonitor);

    if(enable)
    {
        glfwGetWindowPos(_window, &_lastWindowPos[0], &_lastWindowPos[1]);
        glfwGetWindowSize(_window, &_lastWindowSize[0], &_lastWindowSize[1]);

        glfwSetWindowMonitor(_window, _primaryMonitor,
                             0, 0, vidMode->width,
                             vidMode->height, vidMode->refreshRate);
    }
    else
    {
        glfwSetWindowMonitor(_window, nullptr,
                             _lastWindowPos[0], _lastWindowPos[1],
                             _lastWindowSize[0], _lastWindowSize[1],
                             vidMode->refreshRate);
    }
}

bool Window::IsFullScreen()
{
    return glfwGetWindowMonitor(_window) != nullptr;
}

void Window::SetTitle(const std::string& title)
{
    glfwSetWindowTitle(_window, title.c_str());
}

void Window::PollEvents()
{
    glfwPollEvents();
}

void Window::SwapBuffers()
{
    glfwSwapBuffers(_window);
}

void Window::SetShouldClose()
{
    glfwSetWindowShouldClose(_window, GLFW_TRUE);
}

bool Window::GetShouldClose()
{
    return glfwWindowShouldClose(_window) == GLFW_TRUE;
}

Window::~Window()
{
    glfwDestroyWindow(_window);
    glfwTerminate();
}

GLFWwindow* Window::GetGlfwWindow()
{
    return _window;
}
