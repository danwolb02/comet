#define COMET_IMPLEMENTATION

#include <comet/external.hpp>
#include <comet/graphics/window.hpp>

namespace comet
{
Window::Window(const u32 width, const u32 height, const String &title)
{
    if (!glfwInit()) throw RuntimeError("Unable to initialize GLFW.");

    glfwDefaultWindowHints();
    glfwWindowHint(GLFW_VISIBLE, GLFW_TRUE);
    glfwWindowHint(GLFW_RESIZABLE, GLFW_TRUE);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MAJOR, 4);
    glfwWindowHint(GLFW_CONTEXT_VERSION_MINOR, 1);

    handle = glfwCreateWindow(width, height, (const char *)title.c_str(), nullptr, nullptr);
    if (!handle) throw RuntimeError("Unable to create window.");

    glfwMakeContextCurrent((GLFWwindow *)handle);
    glfwSwapInterval(1);

    if (glewInit()) throw RuntimeError("Unable to initialize GLEW.");
}

Window::~Window()
{
    glfwDestroyWindow((GLFWwindow *)handle);
    glfwTerminate();
}

auto Window::update() -> void
{
    glfwPollEvents();
    glfwSwapBuffers((GLFWwindow *)handle);
}

auto Window::should_close() -> bool
{
    return glfwWindowShouldClose((GLFWwindow *)handle);
}

} // namespace comet

