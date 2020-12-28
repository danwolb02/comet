#define COMET_IMPLEMENTATION

#include <comet/external.hpp>
#include <comet/graphics/renderer.hpp>
#include <comet/mathematics/matrix.hpp>
#include <iostream>

namespace comet
{
Renderer::Renderer(const Window &window)
: window(window)
{
	glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

auto Renderer::render(const VertexArray &vertex_array, const Shader &shader,
					  const Matrix4f &transformation_matrix,
					  const Matrix4f &view_matrix,
					  const Matrix4f &projection_matrix) -> void
{
	// Orthographic, origin is top left
	// Matrix4f projection_matrix = orthographic(0, window.get_width(),
	// window.get_height(), 0, -5.0f, 5.0f);

	// Orthographic, origin is center
	// Matrix4f projection_matrix = orthographic(-((i32) window.get_width() /
	// 2), window.get_width() / 2, window.get_height() / 2, -((i32)
	// window.get_height() / 2), -5.0f, 5.0f);

	GL_CALL(glViewport(0, 0, window.get_width(), window.get_height()));
	GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
	shader.use();
	shader.upload(projection_matrix, "projection_matrix");
	shader.upload(view_matrix, "view_matrix");
	shader.upload(transformation_matrix, "transformation_matrix");
	vertex_array.draw();
}

} // namespace comet
