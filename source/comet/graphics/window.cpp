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

	handle = glfwCreateWindow(width, height, (const char *) title.c_str(),
							  nullptr, nullptr);
	if (!handle) throw RuntimeError("Unable to create window.");

	glfwMakeContextCurrent((GLFWwindow *) handle);
	glfwSwapInterval(1);

	if (glewInit()) throw RuntimeError("Unable to initialize GLEW.");
}

Window::~Window()
{
	glfwDestroyWindow((GLFWwindow *) handle);
	glfwTerminate();
}

auto Window::update() const -> void
{
	glfwPollEvents();
	glfwSwapBuffers((GLFWwindow *) handle);
}

auto Window::should_close() const -> bool
{
	return glfwWindowShouldClose((GLFWwindow *) handle);
}

auto Window::get_width() const -> u32
{
	i32 ret = 0;
	glfwGetWindowSize((GLFWwindow *) handle, &ret, nullptr);
	if (ret < 0) throw RuntimeError("Unable to get window width");
	return (u32) ret;
}

auto Window::get_height() const -> u32
{
	i32 ret = 0;
	glfwGetWindowSize((GLFWwindow *) handle, nullptr, &ret);
	if (ret < 0) throw RuntimeError("Unable to get window width");
	return (u32) ret;
}

} // namespace comet
