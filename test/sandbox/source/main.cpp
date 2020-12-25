#include <comet/base.hpp>
#include <comet/graphics/window.hpp>
#include <comet/graphics/vertex_buffer.hpp>
#include <comet/graphics/index_buffer.hpp>
#include <comet/graphics/vertex_array.hpp>
#include <comet/graphics/renderer.hpp>

using namespace comet;

int main()
{
    Window window(1280, 720, "Comet Application");
    VertexBuffer vertex_buffer({-0.5f, -0.5f,
                                 0.5f, -0.5f,
                                 0.0f,  0.5f });
    IndexBuffer index_buffer({0, 1, 2});
    VertexArray vertex_array(move(index_buffer));
    vertex_array.upload(move(vertex_buffer), 0, 2, 0);

    Renderer renderer;

    while (!window.should_close())
    {
        window.update();
        renderer.render(vertex_array);
    }

    return 0;
}
