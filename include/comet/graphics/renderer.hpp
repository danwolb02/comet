#pragma once

#include <comet/graphics/vertex_array.hpp>
#include <comet/graphics/shader.hpp>

namespace comet
{
class Renderer
{
public:
    Renderer();

    ~Renderer() = default;

    auto render(const VertexArray &vertex_array, const Shader &shader) -> void;
};

}
