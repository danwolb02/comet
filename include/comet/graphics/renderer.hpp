#pragma once

#include <comet/graphics/primitives/shader.hpp>
#include <comet/graphics/primitives/vertex_array.hpp>
#include <comet/graphics/window.hpp>
#include <comet/mathematics/matrix.hpp>

namespace comet
{
class Renderer
{
  public:
	explicit Renderer(const Window &window);

	~Renderer() = default;

	auto render(const VertexArray &vertex_array, const Shader &shader,
				const Matrix4f &transformation_matrix,
				const Matrix4f &view_matrix, const Matrix4f &projection_matrix)
	-> void;

  private:
	const Window &window;
};

} // namespace comet
