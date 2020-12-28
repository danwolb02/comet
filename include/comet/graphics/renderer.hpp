#pragma once

#include <comet/graphics/primitives/shader.hpp>
#include <comet/graphics/primitives/vertex_array.hpp>

namespace comet
{
class Renderer
{
  public:
	Renderer();

	~Renderer() = default;

	auto render(const VertexArray &vertex_array, const Shader &shader) -> void;
};

} // namespace comet
