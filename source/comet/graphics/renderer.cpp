#define COMET_IMPLEMENTATION

#include <comet/external.hpp>
#include <comet/graphics/renderer.hpp>
#include <iostream>

namespace comet
{
Renderer::Renderer()
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

auto Renderer::render(const VertexArray &vertex_array, const Shader &shader)
-> void
{
	GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
	shader.use();
	vertex_array.draw();
}

} // namespace comet
