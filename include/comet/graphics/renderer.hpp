#pragma once

#include <comet/graphics/vertex_array.hpp>

namespace comet
{
class Renderer
{
public:
    Renderer() = default;

    ~Renderer() = default;

    auto render(const VertexArray &vertex_array) -> void;
};

}
