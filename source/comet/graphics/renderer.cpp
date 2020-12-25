#define COMET_IMPLEMENTATION

#include <iostream>

#include <comet/external.hpp>
#include <comet/graphics/renderer.hpp>

namespace comet
{
auto Renderer::render(const VertexArray &vertex_array) -> void
{
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
    vertex_array.draw();
}

}
