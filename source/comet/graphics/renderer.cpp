#define COMET_IMPLEMENTATION

#include <iostream>

#include <comet/external.hpp>
#include <comet/graphics/renderer.hpp>

namespace comet
{
Renderer::Renderer()
{
    glClearColor(1.0f, 1.0f, 1.0f, 1.0f);
}

auto Renderer::render(const VertexArray &vertex_array, const Shader &shader) -> void
{
    GL_CALL(glClear(GL_COLOR_BUFFER_BIT));
    shader.use();
    vertex_array.draw();
}

}
